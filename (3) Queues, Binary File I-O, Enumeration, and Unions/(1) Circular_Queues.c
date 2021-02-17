// This is just a brief overview of how circular queues (and queues in general) work. For a more in-depth
// implementation of these concepts see the Week 4, Part A Group Project:
// https://github.com/amwheeler1/CISP1020/tree/main/(98)%20Group%20Projects/Week%204/PartA

#include <stdio.h>

// The maximum size of the queue
#define QUEUE_SIZE 5

// All data needed for a circular queue to work
typedef struct queue {
	int data [QUEUE_SIZE];
	int head, tail;
	int qSize;
} Queue;

void initQ (Queue* q);
int enqueue (Queue* q, int data);
int dequeue (Queue* q, int* data);

int main () {
    // A queue is a first-in, first-out (FIFO) data structure. The first data to be brought into the
    // queue is the first to be taken out.
    
    // A queue has two operations: enqueue (shift) and dequeue (unshift)
    // ENQUEUE [ ] -> 
    //                [ ]
    //                [ ]
    //                [ ]
    //                    -> [ ] DEQUEUE
    Queue q;
    initQ (&q);
    
    // An item is enqueued when it is placed at the tail (rear) of the queue
    enqueue (&q, 10);
    
    // An item is dequeue when it is pulled out of the queue from the head (front) of the queue.
    int dequeuedVal;
    dequeue (&q, &dequeuedVal);
    
    // Linear implementations of queues tend to be inefficient as all data in the queue has to be
    // shifted when information is queued or dequeued. To solve this, circular queues with a head and
    // tail index are utilized.
}

void initQ (Queue* q) {
	// The head pointer is initialized to 0 and the tail is initialized to whatever the queue's
	// maximum size is minus 1
	q->head = 0;
	q->tail = QUEUE_SIZE-1;

	// The current size of the queue is set to 0 as it is empty
	q->qSize = 0;
}

int enqueue (Queue* q, int data) {
	// If the queue is not full yet
	if (q->qSize < QUEUE_SIZE) {
		// Increment the size of the queue
		++(q->qSize);

		// Increment the tail of the queue modulous the queue's maximum size
		q->tail = (q->tail + 1) % QUEUE_SIZE;

		// Set the data at the queue's tail to be the new data
		q->data[q->tail] = data;

		// Return true (1)
		return 1;
	}

	// The queue is full, return false (0)
	else
		return 0;
}

int dequeue (Queue* q, int* data) {
	// If the queue is not empty
	if (q->qSize > 0) {
		// Decrement the size of the queue
		--(q->qSize);

		// Put the data taken out of the queue into the variable
		*data = q->data[q->head];

		// Increment the head of the queue modulous the queue's maximum size
		q->head = (q->head + 1) % QUEUE_SIZE;

		// Return true (1)
		return 1;
	}

	// The queue is empty, return false (0)
	else
		return 0;
}
