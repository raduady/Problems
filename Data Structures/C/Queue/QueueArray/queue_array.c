#include "queue_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_queue_array (QueueArray* Q, int cap) {
	Q -> q = malloc (cap * sizeof(void*));	
	Q -> cap = cap;
	Q -> dim = 0;
	Q -> first = 0;	
	Q -> last = cap - 1;
}

void enqueue_array (QueueArray* Q, void* x, size_t size) {
	if (Q -> dim >= Q -> cap) {
		fprintf (stderr, "The queue is full!\n");
	}	
	Q -> last = (Q -> last + 1) % (Q -> cap);
	void* p = malloc(size);	
	memcpy (p, x, size);
	Q -> q[Q -> last] = p; 
	(Q -> dim)++;
}

void* dequeue_array (QueueArray* Q) {
	if(empty_queue_array(*Q)) {
		fprintf (stderr, "The queue is empty!\n");
		return NULL;
	}	
	void* p = Q -> q[Q -> first];
	Q -> first = (Q -> first + 1) % Q -> cap;
	(Q -> dim)--;
	return p;	
}


int empty_queue_array (QueueArray Q) {
	return (Q.dim == 0);
} 
