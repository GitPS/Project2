#
# Ryan Gittins and Phillip Sime
#
# CS 441: Project 2 Part 1
#
#####################################################################
#
# Type "make" or "make sum" to compile your code
# 
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################

CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-pthread -lm

PROGS=bounded_buffer

all: $(PROGS)

bounded_buffer: bounded_buffer.c bounded_buffer.h semaphore_support.o
	$(CC) -o sum $(CFLAGS) $(LDFLAGS) bounded_buffer.c semaphore_support.o 

semaphore_support.o: semaphore_support.h semaphore_support.c
	$(CC) -c -o semaphore_support.o semaphore_support.c $(CFLAGS)

clean:
	$(RM) $(PROGS) *.o
	$(RM) -rf *.dSYM
