/*
 * Ryan Gittins and Phillip Sime
 * 
 * CS441: Project 2 Part 1
 * 2013-10-16
 * 
 */

#include "bounded_buffer.h"

void *producer(void *threadid);
void *consumer(void *threadid);
semaphore_t mutex;
semaphore_t full;
semaphore_t empty;
buffer_item *buffer = NULL;
int buffer_size = 0;
int in = 0;
int out = 0;

int main(int argc, char * argv[]) {
    int time_to_live = -1;
    int num_producer_threads = -1;
    int num_consumer_threads = -1;
    int rc, i;
	
    long t;

    /* Command line argument handling */
	if(argc < 4) {
		fprintf(stderr, "Error: Not enough arguments!  Terminating.\n");
		exit(0);
	}
	else if(argc == 4) {
		buffer_size = 10;
	}
	else if(argc == 5) {
		buffer_size = (int) strtol(argv[4], NULL, 10);
		/* Verify that the buffer size is a legitimate value */
		if(buffer_size < 1 || buffer_size > 10){
		    fprintf(stderr, "Error: Buffer size must be a number between 0 and 10!  Terminating.\n");
		    exit(0);
		}
	}
	else {
		fprintf(stderr, "Error: Too many arguments!  Terminating.\n");
		exit(0);
	}
	
	time_to_live = (int) strtol(argv[1], NULL, 10);
	num_producer_threads = (int) strtol(argv[2], NULL, 10);
	num_consumer_threads = (int) strtol(argv[3], NULL, 10);
	
	print_header(buffer_size, time_to_live, num_producer_threads, num_consumer_threads);
	
	
	/* Create Semaphores */
	semaphore_create(&mutex, 1);
	semaphore_create(&full, 0);
	semaphore_create(&empty, buffer_size);
	
	/* Seed random number generator */
	srandom(time(NULL));
    
    /* Initialize buffer */
	buffer = (int *) malloc(sizeof(int) * buffer_size);
    if(buffer == NULL){
        fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        exit(-1);
    }
    
    /* Set initial values of the buffer to -1 */
    for(i = 0; i < buffer_size; i++){
        buffer[i] = -1;
    }
    
    /* Print initial buffer */
	printf("Initial Buffer:              [");
	for(i = 0; i < buffer_size; i++){
	    if(in == i && out == i){
            printf("%*d^v", 4, buffer[i]);
        }
        else{
            printf("%*d", 4, buffer[i]);	    
        }
	}
	printf(" ]\n");
    
    /* Create producer thread(s) */
    pthread_t producer_threads[num_producer_threads];
    for(t = 0; t < num_producer_threads; t++){
        rc = pthread_create(&producer_threads[t], NULL, producer, (void *)t);
        if(rc){
            fprintf(stderr, "Error: Could not create thread %ld\n", t);
            exit(-1);
        }        
    }    
        
    /* Create consumer thread(s) */
    pthread_t consumer_threads[num_consumer_threads];
    for(t = 0; t < num_consumer_threads; t++){
        rc = pthread_create(&consumer_threads[t], NULL, consumer, (void *)t);
        if(rc){
            fprintf(stderr, "Error: Could not create thread %ld\n", t);
            exit(-1);
        }        
    }
    
    /* Sleep */
    sleep(time_to_live);
    
    /* Cleanup */
    if(buffer != NULL){
        free(buffer);
        buffer = NULL;
    }

	semaphore_destroy(&mutex);
	semaphore_destroy(&full);
	semaphore_destroy(&empty);
	
	return 0;
}

int print_header(int buffer_size, int time_to_live, int producer_threads, int consumer_threads) {

	printf("Buffer Size               :%4d\n", buffer_size);
	printf("Time To Live (seconds)    :%4d\n", time_to_live);
	printf("Number of Producer threads:%4d\n", producer_threads);
	printf("Number of Consumer threads:%4d\n", consumer_threads);
	printf("-------------------------------\n");
	
	return 0;
}

int insert_item(buffer_item item, long thread_id){
    /* Add the provided item to the buffer */
    buffer[in] = item;

    /* Check to see if we have reached the limit of our buffer.  If we have wrap around. */
    in = (in + 1) % buffer_size;
    
    /* Print buffer */
    int i;
    printf("Producer   %ld: Produced %d     [", thread_id, item);
    for(i = 0; i < buffer_size; i++){
         /* Consumer and Producer in same location */
        if(in == i && out == i){
            printf("%*d^v", 4, buffer[i]);
        }
        /* Producer location */
        else if(in == i){
            printf("%*d^", 4, buffer[i]);
        }
        /* Consumer location */
        else if(out == i){
            printf("%*dv", 4, buffer[i]);
        }
        else{
            printf("%*d", 4, buffer[i]);
        }
    }
    printf(" ]\n");
    
    return 0;
}

int remove_item(long thread_id){
    buffer_item item;
    
    /* Remove the next item from the buffer */
    item = buffer[out];
    buffer[out] = -1;
    
    /* Check to see if we have reached the limit of our buffer.  If we have wrap around. */
    out = (out + 1) % buffer_size;
    
    /* Print buffer */
    int i;
    printf("Consumer   %ld: Consumed %d     [", thread_id, item);
    for(i = 0; i < buffer_size; i++){
         /* Consumer and Producer in same location */
        if(in == i && out == i){
            printf("%*d^v", 4, buffer[i]);
        }
        /* Producer location */
        else if(in == i){
            printf("%*d^", 4, buffer[i]);
        }
        /* Consumer location */
        else if(out == i){
            printf("%*dv", 4, buffer[i]);
        }
        else{
            printf("%*d", 4, buffer[i]);
        }
    }
    printf(" ]\n");
    
    return 0;
}

void *producer(void *threadid){
    buffer_item item;
    long thread_id = (long)threadid;

    while(TRUE){
        /* Sleep for a random period of time */
        usleep(random() % SLEEP_LIMIT);
        
        /* Generate random number */
        item = random() % RANDOM_LIMIT;
		semaphore_wait(&empty);
		semaphore_wait(&mutex);
        
        /* Insert item into buffer */
        insert_item(item, thread_id);
        fflush(NULL);
		
		/* Print Buffer */
		semaphore_post(&mutex);
		semaphore_post(&full);
    }
}

void *consumer(void *threadid){
    long thread_id = (long)threadid;

    while(TRUE){
        /* Sleep for a random period of time */
        usleep(random() % SLEEP_LIMIT);
		semaphore_wait(&full);
		semaphore_wait(&mutex);
		
        /* Remove item from buffer */
        remove_item(thread_id);
        
        /* Print Buffer */
		semaphore_post(&mutex);
		semaphore_post(&empty);
    }
}
