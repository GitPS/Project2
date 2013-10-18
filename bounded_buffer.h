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

#include "semaphore_support.h"

typedef int buffer_item;
#define BUFFER_SIZE 5

/*
 *  TODO
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


#endif /* BOUNDED_BUFFER_H */
