#ifndef __QUEUE_ARRAY_H__
#define __QUEUE_ARRAY_H__

#include <stdio.h>

// FIFO Queue using circular arrays
typedef struct QueueArray {
	void** q;
	int first;
	int last;
	int cap; 
	int dim;
} QueueArray;

// initialize the queue
void init_queue_array (QueueArray*, int);

// enqueue the queue
void enqueue_array (QueueArray*, void*, size_t);

// dequeue the queue
void* dequeue_array (QueueArray*);

// vierifies whether the queue is empty or not 
int empty_queue_array (QueueArray);

#endif
