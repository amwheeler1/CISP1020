/* File: queue.c
 * Author: amwheeler1
 * Description: Contains function definitions for setting up and modifying a queue
*/

#include "queue.h"
#include <stdio.h>

// initQueue
// Initializes queue to be sized 0, and have front and rear pointers pointing to appropriate locations
// Parameters
//     q: A pointer to a queue structure which can be modified
// Precondition : q points to a valid queue
// Postcondition: q has values properly initialized for data modification
// Returns: void

void initQueue (Queue* q) {
	// Count is zero
	q->count = 0;
	// Front of queue is at element 0
	q->front = 0;
	// Rear of queue is at whatever the array size is - 1 (indexed value)
	q->rear  = QUEUE_SIZE-1;
}

// enqueue
// Enqueues a value to the back of a queue if the queue is not full
// Parameters
//     q: A pointer to an initialized queue structure
//     qItem: The value to be put at the end of the queue
// Precondition : q has been initialized
// Postcondition: Either qItem is enqueued if q is not full, or 0 is returned if not
// Returns: 1 if enqueuing was successful, 0 if queue was full
int enqueue (Queue* q, QueueItem qItem) {
	// If queue is not full
	if (q->count < QUEUE_SIZE) {
		// Increment q's count
		++(q->count);
		// Increment%QUEUE_SIZE the rear pointer's location
		q->rear = (q->rear + 1) % QUEUE_SIZE;
		// Put qItem's value into rear pointer's location
		q->array[q->rear] = qItem;
		return 1;
	}

	// Enqueuing unsuccessful if queue is full
	return 0;
}

// dequeue
// Dequeues a value from the front of the queue if the queue is not empty
// Parameters
//     q: A pointer to an initialized queue structure
//     qItem: The value taken from the front of the queue
// Precondition : q has been initialized
// Postcondition: Either a value is taken from the front of the queue and placed in qItem, or 0 is returned if not
// Returns: 1 if dequeuing was successful, 0 if queue was empty
int dequeue (Queue* q, QueueItem* qItem) {
	// If queue is not empty
	if(q->count > 0) {
		// Decrement q's count
		--(q->count);
		// Put value at the front of the queue into qItem
		*(qItem) = q->array[q->front];
		// Increment%QUEUE_SIZE the front pointer's location
		q->front = (q->front + 1) % QUEUE_SIZE;
		return 1;
	}

	// Dequeuing unsuccessful if queue is empty
	return 0;
	
}

// isEmpty
// Tests to see if the queue is empty
// Parameters
//     q: An initialized queue
// Precondition : q has been initialized
// Postcondition: No data is changed; value on q's status is returned
// Returns: 1 if queue was empty, 0 if queue was not empty
int isEmpty (Queue q) {
	// Queue is empty
	if (q.count < 1)
		return 1;

	// Queue is not empty
	else
		return 0;
}

// printQueue
// Prints the values in the queue
// Parameters
//     q: An initialized queue
// Precondition : q has been initialized
// Postcondition: No data is changed
// Returns: void
void printQueue (Queue q) {
	int i;

	// Print information if queue is not empty
	if (q.count > 0) {
		for (i = q.front; i != q.rear; i = (i+1) % QUEUE_SIZE)
			printf("| %4d ", q.array[i]);
	}

	// Print rear value if queue is not empty
	if (q.count > 0)
		printf("| %4d |\n", q.array[q.rear]);

	// Print empty cell if queue is empty
	else
		printf("| |\n");
}
