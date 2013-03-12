#ifndef __QUEUE_LIST_H__
#define __QUEUE_LIST_H__

#include <stdlib.h>

// FIFO Queue using Linked List
typedef struct QueueNode {
	void* key;
	struct QueueNode* next;
} QueueNode;

typedef QueueNode* QueueList;

// initialize the queue
void init_queue_list (QueueList*, QueueList*);

// enqueue the queue
void enqueue_list (QueueList*, QueueList*, void*, size_t);

// dequeue the queue
void* dequeue_list (QueueList*, QueueList*);

// verifies whether the queue is empty or not
int empty_queue_list (QueueList, QueueList);

// return a queue node with a given key
void* make_queue_node (void*, size_t);

#endif
