#ifndef __STACK_ARRAY_H__
#define __STACK_ARRAY_H__

#include <stdlib.h>

// LIFO stack using array
typedef struct StackArray {
	void **st;	
	int cap;
	int dim;
	// load factor
	float lf;
} StackArray;

// initialize the stack
void init_stack_array (StackArray*, int, float);

// push the stack
void push_stack_array (StackArray*, void*, size_t);

// pop the stack
void* pop_stack_array (StackArray*);

// return the first element
void* peek_stack_array (StackArray);

// checks whether the stack is empty or not
int empty_stack_array (StackArray);

#endif
