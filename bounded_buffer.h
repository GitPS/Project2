/*
 * Ryan Gittins and Phillip Sime
 * 
 * CS441: Project 2 Part 1
 * 2013-10-16
 * 
 */
#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "semaphore_support.h"

#define TRUE  1
#define FALSE 0
#define RANDOM_LIMIT 10
#define SLEEP_LIMIT 1000001

typedef int buffer_item;

/*
 * Print header information.
 *   buffer : size of buffer
 *   lifespawn : time in seconds program should run for
 *   producers : number of producer threads
 *   consumers : number of consumer threads
 * Returns 0 on success
 */
int print_header(int buffer, int lifespan, int producers, int consumers);
 
/*
 * Insert an item info the buffer.
 *   item : item to insert into buffer
 *   thread_id : thread id of the calling thread
 * Returns 0 on success
 */
int insert_item(buffer_item item, long thread_id);

/*
 * Insert an item info the buffer.
 *   thread_id : thread id of the calling thread
 * Returns 0 on success
 */
int remove_item(long thread_id);

/*
 * Thread that will produce random items to place into a buffer.
 * This thread will also sleep for random amounts of time before
 * each item is produced.
 *   threadid : thread id in relation to the order it was created
 * Returns 0 on success
 */
void *producer(void *threadid);

/*
 * Thread that will consume the next item from a buffer.
 * This thread will also sleep for random amounts of time before
 * it consumes the next item.
 *   threadid : thread id in relation to the order it was created
 * Returns 0 on success
 */
void *consumer(void *threadid);



#endif /* BOUNDED_BUFFER_H */
