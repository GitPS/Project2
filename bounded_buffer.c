/*
 * Ryan Gittins and Phillip Sime
 * 
 * CS441: Project 2 Part 1
 * 2013-10-16
 * 
 */

#include "bounded_buffer.h"

int main(int argc, char * argv[]) {
    int *buffer = NULL;
	int buffer_size = -1;
	int time_to_live = -1;
	int producer_threads = -1;
	int consumer_threads = -1;

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
	producer_threads = (int) strtol(argv[2], NULL, 10);
	consumer_threads = (int) strtol(argv[3], NULL, 10);
	
	print_header(buffer_size, time_to_live, producer_threads, consumer_threads);
    
    /* Initialize buffer */
	buffer = (int *) malloc(sizeof(int) * buffer_size);
    if(buffer == NULL){
        fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        exit(-1);
    }
    
    // TODO
    /* Create producer thread(s) */
    /* Create consumer thread(s) */
    /* Sleep */
    /* Exit */
    
    /* Cleanup */
    if(buffer != NULL){
        free(buffer);
        buffer = NULL;
    }

	return 1;
}

int print_header(int buffer_size, int time_to_live, int producer_threads, int consumer_threads) {

	printf("Buffer Size               :%4d\n", buffer_size);
	printf("Time To Live (seconds)    :%4d\n", time_to_live);
	printf("Number of Producer threads:%4d\n", producer_threads);
	printf("Number of Consumer threads:%4d\n", consumer_threads);
	printf("-------------------------------\n");
	
	return 1;
}

int insert_item(buffer_item item){
   
    return 0;
}

int remove_item(buffer_item *item){
    
    return 0;
}
