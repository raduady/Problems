#include "queue_list.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


// Impelementation of a Queue using LinkedList
// Enqueue: O(1) time, Dequeue: O(1) time
void init_queue_list (QueueList* front, QueueList* rear) {
	*front = NULL;
	*rear = NULL;	
}

void enqueue_list (QueueList* front, QueueList* rear, void* x, size_t size) {
	QueueNode* p = make_queue_node (x, size);
	if(empty_queue_list(*front, *rear)) {
		*rear = p;
		*front = p;
	}
	(*rear) -> next = p;
	*rear = p;
}

void* dequeue_list (QueueList* front, QueueList* rear) {
	if (empty_queue_list (*front, *rear)) {
		fprintf(stderr, "The Queue is empty!\n");
		return NULL;
	}	
	QueueNode* node = *front;
	*front = (*front) -> next;
	void* v = node -> key;
	free(node);
	return v;	
}

int empty_queue_list (QueueList front, QueueList rear) {
	return (front == NULL || rear == NULL);
}

void* make_queue_node (void* x, size_t size) {
	QueueNode* node = malloc (sizeof(QueueNode));
	void* p = malloc (size); 
	memcpy (p, x, size);
	node -> key = p;
	node -> next = NULL;
	return node; 
}
