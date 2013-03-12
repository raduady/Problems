#include "stack_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Descritpion: initialize the stack
// Time Complexity: O(1)
void init_stack_list (StackList* st) {
	*st = NULL;
}

// Description: pop the stack
// Time Complexity: O(1)
void* pop_stack_list (StackList* st) {
	if (empty_stack_list(*st)) {
		fprintf(stderr, "Stack is empty!\n");
		return NULL;
	}
	StackNode* p = *st;	
	*st = (*st) -> next;
	void* value = p -> key;
	free(p);
	return value;
}

// Description: push the list
// Time Complexity: O(1)
void push_stack_list (StackList* st, void* x, size_t size) {
	StackNode* p = make_stack_node(x, size);	
	p -> next = *st;
	*st = p;
}

// Description: checks whether the stack is empty or not
// Time Complexity: O(1)
int empty_stack_list (StackList st) {
	return (st == NULL);
}

// Description: return the element in the front of the list
// Time Complexity: O(1)
void* peek_stack_list (StackList st) {
	if (empty_stack_list(st)) {
		fprintf(stderr, "Stack is empty!\n");
		return NULL;
	}	
	return st -> key;
} 

// Desciption: return a node with the key x
// Time Complexity: O(1)
StackNode* make_stack_node(void* x, size_t size) {
	StackNode* node = malloc(sizeof(StackNode));
	void* p = malloc(size);
	memcpy(p, x, size);
	node -> key = p;
	node -> next = NULL;
	return node;
}
