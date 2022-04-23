#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{

	q->head = q->tail = NULL;

}

void destroyQueue(Queue* q) //שחרור הזיכרון הדינאמי שמנוהל ע"י המבנה המנהל של התור
{
	
	while (!isEmptyQueue(q)) 
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
	{
		printf("allocation failed!!");
		return;
	}
}

unsigned int dequeue(Queue* q)
{

	if (isEmptyQueue(q)) {
		printf("is Empty");
		return 0;
	}
	int hold = q->head->data;  //שומרת ערך להחזרה
	intNode* pOldHead = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(pOldHead);
	return hold;
}

int isEmptyQueue(const Queue* q)
{

	if (q->head == NULL && q->tail == NULL)
		return 1;
	return 0;

}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q) // לטפל בקוד
{


	//Queue s1, s2;
	//initQueue(&s1);
	//initQueue(&s2);
	//while (!isEmptyQueue(q)) {
	//	while (!isEmptyQueue(&s1)) {
	//		enqueue(&s2, dequeue(&s1));
	//	}
	//	enqueue(&s1, dequeue(s));
	//	while (!isEmptyQueue(&s2)) {
	//		enqueue(&s1, dequeue(&s2));
	//	}
	//}
	//while (!isEmptyQueue(&s1)) {
	//	enqueue(q, dequeue(&s1));
	//}


	/*Queue s1, s2;
	initQueue(&s1);
	initQueue(&s2);
	while (!isEmptyQueue(q)) {
		while (!isEmptyQueue(&s1)) {
			enqueue(&s2, dequeue(&s1));
		}
		enqueue(&s1, dequeue(s));
		while (!isEmptyQueue(&s2)) {
			enqueue(&s1, dequeue(&s2));
		}
	}
	while (!isEmptyQueue(&s1)) {
		enqueue(q, dequeue(&s1));
	}*/
}


void cutAndReplace(Queue* q)  // לטפל בקוד
{
	Queue s1, s2;
	initQueue(&s1);
	initQueue(&s2);
	int c = 0;
	int x = 0;
	if (isEmptyQueue(q)) {
		printf("Empty queue!");
		return;
	}
	while (!isEmptyQueue(q)) {
		c++;
		x += q->head->data;
		enqueue(&s2, dequeue(q));
	}
	if (c % 2 != 0) {
		x = x / c;
		enqueue(&s2, x);
		c++;
		for (int i = 0; i < c / 2; i++)
			enqueue(&s1, dequeue(&s2));
		reverse(&s2);
		for (int i = 0; i < c / 2; i++)
			enqueue(&s2, dequeue(&s1));
	}
	else {
		for (int i = 0; i < c / 2; i++)
			enqueue(&s1, dequeue(&s2));
		reverse(&s2);
		for (int i = 0; i < c / 2; i++)
			enqueue(&s2, dequeue(&s1));
	}
	print(&s2);
}

void sortKidsFirst(Queue* q)
{
	Queue tmpQ;
	Queue tmpQ2;
	initQueue(&tmpQ);
	initQueue(&tmpQ2);
	int min;
	int val2;
	while (1)
	{
		min = 1000000;//סתם ערך
		while (!isEmptyQueue(q))//מציאת האיבר הכי קטן
		{
			val2 = dequeue(q);
			if (min >= val2)
				min = val2;
			enqueue(&tmpQ, val2);
		}
		enqueue(&tmpQ2, min);//tmpQ2 העברת האיבר הקטן ל
		while (!isEmptyQueue(&tmpQ))//q הוצאת האיבר הקטן מהתור והחזרת שאר האיברים לתור
		{
			val2 = dequeue(&tmpQ);
			if (val2 == min)
				continue;
			else
				enqueue(q, val2);
		}
		if (isEmptyQueue(q))//בדיקה האם נבדקו כל איברי התור המקורי
			break;
	}
	enqueue(q, dequeue(&tmpQ2));
	while (!isEmptyQueue(&tmpQ2))//q אחרי סידור האיברים,החזרה ל
		enqueue(q, dequeue(&tmpQ2));
}

