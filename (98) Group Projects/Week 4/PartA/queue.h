/* File: queue.h
 * Author: amwheeler1
 * Description: Contains type and constant definitions for the program along with function prototypes
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "queueItem.h"

#define QUEUE_SIZE 10
#define EMPTY_INDEX -1

typedef struct queue {
	QueueItem array [QUEUE_SIZE];
	int front, rear;
	int count;
} Queue;

void initQueue (Queue* q);
int enqueue (Queue* q, QueueItem qItem);
int dequeue (Queue* q, QueueItem* qItem);
int isEmpty (Queue q);
void printQueue (Queue q);

#endif
