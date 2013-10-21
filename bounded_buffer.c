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
buffer_item *buffer = NULL;

int main(int argc, char * argv[]) {
    int buffer_size = -1;
    int time_to_live = -1;
    int num_producer_threads = -1;
    int num_consumer_threads = -1;
    int rc, i;
	
    long t;
	
	semaphore_t mutex;
	semaphore_create(&mutex, 1); 

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
		if(buffer_size < 0 || buffer_size > 10){
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
	
	/* Loop until time_to_live seconds have elapsed */
	int start_time = (int)time(NULL);
	
	while((int)time(NULL) - start_time < time_to_live) {
	
		semaphore_wait(&mutex);
		
		/*** Critical Section ***/
		/* Produce or Consume */
		/* Increment or Decrement */
		/* Print buffer */
		
		semaphore_post(&mutex);
		
		/*** Remainder Section ***/
		/* Sleep for up to one second */
	
	}
    
    /* Sleep */
    // TODO
    sleep(5);
    /* Exit */
    // TODO
    
    /* Cleanup */
    if(buffer != NULL){
        free(buffer);
        buffer = NULL;
    }
    
    //pthread_exit(NULL);

	semaphore_destroy(&mutex);
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

int insert_item(buffer_item item){
    // TODO
    // This should insert an item into the buffer.
    // It must lock the buffer before it inserts.   
    return 0;
}

int remove_item(buffer_item *item){
    // TODO
    // This should insert an item into the buffer.
    // It must lock the buffer before it removes.
    return 0;
}

void *producer(void *threadid){
    buffer_item item;
    int r;
    while(TRUE){
        /* Sleep for a random period of time */
        usleep(random() % SLEEP_LIMIT);
        /* Generate random number */
        r = random() % RANDOM_LIMIT;
        /* Insert item into buffer */
        // TODO
    }
}

void *consumer(void *threadid){
    buffer_item item;
    while(TRUE){
        /* Sleep for a random period of time */
        usleep(random() % SLEEP_LIMIT);
        /* Remove item from buffer */
        // TODO
    }
}
