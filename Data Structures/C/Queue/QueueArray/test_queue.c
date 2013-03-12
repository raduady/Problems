#include "queue_array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
	QueueArray q;	
	int i;
	init_queue_array (&q, 100);
//	for (i = 0; i < 10; i++)
//		enqueue_array(&q, &i, sizeof(int));

//	for (i = 0; i < 10; i++) {
//		printf ("%d ", *(int*)dequeue_array(&q));
//	}

	char* str = (char*) malloc (10 * sizeof(char));
	sprintf (str, "ana");
	enqueue_array (&q, str, sizeof(str));
	sprintf (str, "are");
	enqueue_array (&q, str, sizeof(str));
	sprintf (str, "mere");
	enqueue_array (&q, str, sizeof(str));

	for (i = 0; i < 3; i++)
		printf ("%s\n", (char*)dequeue_array (&q));

	return 0;
}

