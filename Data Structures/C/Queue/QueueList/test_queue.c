#include "queue_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void) {
	QueueList front, rear;
	int i;
	init_queue_list (&front, &rear);

	//for (i = 0; i < 10; i++)
	//	enqueue_list (&front, &rear, &i, sizeof(int));
	//
	//for (i = 0; i < 10; i++)
	//	printf ("%d ", *(int*)dequeue_list (&front, &rear));

	char* str = (char*) malloc (10 * sizeof(char));
	sprintf (str, "ana");
	enqueue_list (&front, &rear, str, sizeof(str));
	sprintf (str, "are");
	enqueue_list (&front, &rear, str, sizeof(str));
	sprintf (str, "mere");
	enqueue_list (&front, &rear, str, sizeof(str));

	for (i = 0; i < 3; i++)
		printf ("%s ", (char*)dequeue_list (&front, &rear));
	return 0;
}
