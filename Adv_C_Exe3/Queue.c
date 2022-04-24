#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

/***************** Queue ADT Implementation *****************/
void printQueue(Queue* q);
void initQueue(Queue* q)
{

	q->head = q->tail = NULL;

}

void destroyQueue(Queue* q) //����� ������� ������� ������ �"� ����� ����� �� ����
{
	unsigned int noMetherHold;
	while (!isEmptyQueue(q)) 
		noMetherHold=dequeue(q);//����� ��� ����� ���� �����
	//free(&q);
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
		printf("allocation failed!!\n");
		return;
	}
}

unsigned int dequeue(Queue* q)
{

	if (isEmptyQueue(q)) {
		printf("is Empty\n");
		return 0;
	}
	int hold = q->head->data;  //����� ��� ������
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

void rotateQueue(Queue* q) // ���� ����
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


	Queue TmpQueue1;//��� ���1
	Queue TmpQueue2;//��� ��� 2
	initQueue(&TmpQueue1);//����� ���� ���
	initQueue(&TmpQueue2);//����� ���� ���2
	//int res;//����� ������ �� �� ���� ��������

	while (!(isEmptyQueue(q)))//�� ��� ���� �� ���
	{
		while (!(isEmptyQueue(&TmpQueue1)))
		{
			enqueue(&TmpQueue2, dequeue(&TmpQueue1));
		}
		enqueue(&TmpQueue1, dequeue(q));

		while (!isEmptyQueue(&TmpQueue2))
		{
			enqueue(&TmpQueue1, dequeue(&TmpQueue2));
		}
		//res = dequeue(q);//����� ���� ������ ���� ������
		//if (isEmptyQueue (q))//����� �� ����� ����� ������ ��� �� �� ������
		//{
		//	enqueue (&TmpQueue2, res);//���� ����� ������ ���� ��� ����
			//break;//����� ���� �� ���
		//}

		//enqueue(&TmpQueue1, res);//������� �� ������ ���� ��� 1

	}
	//���� ���� ����

	while (!isEmptyQueue(&TmpQueue1))//����� ������ ���� ��� 1 ������ �����
	{
		enqueue(q, dequeue(&TmpQueue1));

	}

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


void cutAndReplace(Queue* q)  // ���� ����
{
	Queue s1, s2;
	initQueue(&s1);
	initQueue(&s2);
	int c = 0;
	int x = 0;
	if (isEmptyQueue(q)) {
		printf("Empty queue!\n");
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
		rotateQueue(&s2);
		for (int i = 0; i < c / 2; i++)
			enqueue(&s2, dequeue(&s1));
	}
	else {
		for (int i = 0; i < c / 2; i++)
			enqueue(&s1, dequeue(&s2));
		rotateQueue(&s2);
		for (int i = 0; i < c / 2; i++)
			enqueue(&s2, dequeue(&s1));
	}
	printQueue(&s2);
	
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
		min = 1000000;//��� ���
		while (!isEmptyQueue(q))//����� ����� ��� ���
		{
			val2 = dequeue(q);
			if (min >= val2)
				min = val2;
			enqueue(&tmpQ, val2);
		}
		enqueue(&tmpQ2, min);//tmpQ2 ����� ����� ���� �
		while (!isEmptyQueue(&tmpQ))//q ����� ����� ���� ����� ������ ��� ������� ����
		{
			val2 = dequeue(&tmpQ);
			if (val2 == min)
				continue;
			else
				enqueue(q, val2);
		}
		if (isEmptyQueue(q))//����� ��� ����� �� ����� ���� ������
			break;
	}
	enqueue(q, dequeue(&tmpQ2));
	while (!isEmptyQueue(&tmpQ2))//q ���� ����� �������,����� �
		enqueue(q, dequeue(&tmpQ2));
}

