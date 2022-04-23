#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{

	q->head = NULL;
	q->tail == NULL;

}

void destroyQueue(Queue* q)
{
	int e; // empti
	e = isEmptyQueue;
	if (e==1)
	//while (!isEmptyQueue(q))  אופציה לפונקציה בלי משתנה
		dequeue(q);
	free(q);
}

void enqueue(Queue* q, unsigned int data)
{

	intNode* newToLest = (intNode*)calloc(1, sizeof(intNode));
	if (newToLest != NULL) {
		newToLest->data = data;
		if (!isEmptyQueue(q))
		{
			q->tail->next = newToLest;
			q->tail = newToLest;
			return;
		}
		q->tail = q->head = newToLest;
	}
	else
		return;
}

unsigned int dequeue(Queue* q)
{
	// add your code here
}

int isEmptyQueue(const Queue* q)
{

	if (q->head == NULL && q->tail == NULL)
		return 1;
	return 0;

}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}