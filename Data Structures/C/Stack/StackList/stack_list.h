#ifndef __STACK_LIST_H__
#define __STACK_LIST_H__

#include <stdlib.h>

// a LIFO stack using linked list
typedef struct StackNode {
	void* key;
	struct StackNode* next;
} StackNode;

typedef StackNode* StackList;

// initialize stack
void init_stack_list (StackList*);

// pop the stack and return the last introduced element
void* pop_stack_list (StackList*);

// push an element in front of the stack
void push_stack_list (StackList*, void*, size_t);

// verify whether the stack is empty or not
int empty_stack_list (StackList);

// return the last element introduced in the stack without removing it
void* peek_stack_list (StackList);

// return a stack node
StackNode* make_stack_node (void*, size_t);

#endif
