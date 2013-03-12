#include "stack_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Description: initialize the stack
// Time Complexity: O(1)
void init_stack_array (StackArray* s, int cap, float lf) {
	s -> st = malloc(cap * sizeof(void*));
	s -> cap = cap;
	s -> dim = 0;
	s -> lf = lf;
}

// Description: push the stack
// Time Complexity: O(n), but on a sequence of n push operations
// the amortized cost is O(3n / n) = O(3) = O (1).
void push_stack_array  (StackArray* s, void* x, size_t size) {
	if (s -> dim == s -> cap) {
		s -> cap *= (int)(1 / (s -> lf));
		s -> st = realloc (s -> st, (s -> cap) * sizeof(void*));
	}	
	void *p = malloc(size);
	memcpy(p, x, size);
	s -> st[(s -> dim)++] = p;
}

// Description: pop the stack
// Time Complexity: O(1)
void* pop_stack_array (StackArray* s) {
	return s -> st[--(s -> dim)];	
}

// Descritpion: return the last element introduced in the stack
// Time Complexity: O(1)
void* peek_stack_array (StackArray s) {
	return s.st[(s.dim) - 1];
}

// Description: verifies whether the stack is empty or not
// Time Complexity: O(1)
int empty_stack_array (StackArray s) {
	return s.dim == 0;	
}
