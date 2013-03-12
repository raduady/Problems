#include "stack_array.h"
#include <stdio.h>

int main (void) {
	StackArray st;	
	int i;

	init_stack_array (&st, 2, 0.5);
	
	char* str = (char*) malloc(10 * sizeof(char));
	sprintf(str, "ana");
	push_stack_array(&st, str, sizeof(str));
	sprintf(str, "are");
	push_stack_array(&st, str, sizeof(str));
	sprintf(str, "aree");
	push_stack_array(&st, str, sizeof(str));
//	for (i = 0; i < 10; i++)
//		push_stack_array (&st, &i, sizeof(int));
//
//	for (i = 0; i < 10; i++)
//		printf ("%d ", *(int*)pop_stack_array(&st));

	for (i = 0; i < 3; i++)
		printf ("%s\n", (char*)pop_stack_array(&st));
	
	return 0;
}
