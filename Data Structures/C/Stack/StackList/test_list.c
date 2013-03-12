#include "stack_list.h"
#include <stdio.h>

int main (void) {
	StackList st;
	int i;
	init_stack_list (&st);

	for (i = 0; i < 10; i++) {
		push_stack_list (&st, &i, sizeof(i));	
	}

	for (i = 0; i < 10; i++) {
		printf ("%d ", *(int*) pop_stack_list (&st));
	}
	return 0;
}
