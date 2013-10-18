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
#define SLEEP_LIMIT 1000000

typedef int buffer_item;

/*
 * TODO
 */
int print_header(int buffer, int lifespan, int producers, int consumers);
 
/*
 * TODO
 */
int insert_item(buffer_item item);

/*
 * TODO
 */
int remove_item(buffer_item *item);

/*
 * TODO
 */
void *producer(void *param);

/*
 * TODO
 */
void *consumer(void *param);



#endif /* BOUNDED_BUFFER_H */
