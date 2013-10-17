/*
 * Ryan Gittins and Phillip Sime
 * 
 * CS441: Project 2 Part 1
 * 2013-10-16
 * 
 */
#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H

/* For fork, exec, sleep */
#include <sys/types.h>
#include <unistd.h>
/* For waitpid */
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>

/*
 *  TODO
 */
int print_header(int buffer, int lifespan, int producers, int consumers);
 
#endif /* BOUNDED_BUFFER_H */