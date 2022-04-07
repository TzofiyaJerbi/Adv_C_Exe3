#include "Stack.h"

#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* pointerToHead;
	pointerToHead = (charNode*)malloc(sizeof(charNode));
	if (pointerToHead) {//����� �� ������ �� ����� 

		while ((s->head) != NULL)
		{
			pointerToHead = (s->head);
			s->head = s->head->next;
			free(pointerToHead);
		} printf("success! naw the stack is empty \n");
	}
	else //����� �����
	{
		printf("can't destroy Stack\n ");
	}
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL) //����� �� ������ �����
	{
		printf("no memory!!\n");
		return;
	}

	newnode->data = data;
	newnode->next = s->head;
	s->head = newnode;
}

char pop(Stack* s)
{
	if (isEmptyStack(s))		// ���� ������ ���� ���� ��� �- ������ ����� 
	{
		printf("the stack is empty\n");
		exit(1);
	}

	char res = s->head->data;			//  ������ �� ����, ����� ����, ����� ���� ������ ���� ������
	charNode* tmp = s->head;
	s->head = s->head->next;
	free(tmp);
	return res;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;				// ����� 1: ���, ����� �����0  ������ ����
	else
		return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	char res;
	Stack OriginalStack;
	Stack TmpStack1;
	Stack TmpStack2;
	initStack(&OriginalStack);
	initStack(&TmpStack1);
	initStack(&TmpStack2);
	int i = (strlen(sentence) - 1);
	while (i > -1)
	{
		push(&OriginalStack, sentence[i]);//���� �� ����� �������
		i--;
	}

	while (!(isEmptyStack(&OriginalStack)))//�� ��� ������� �� ����
	{
		while (1)
		{
			res = pop(&OriginalStack);//������� �� ��
			if (res == '#')//����� �� ����� �#
				break;
			push(&TmpStack1, res);//������ ���1
		}


		while (1)
		{
			if (isEmptyStack(&OriginalStack))
				break;
			res = pop(&OriginalStack);
			if (res == '#')
				break;

			push(&TmpStack2, res);//������ ���2
		}

		while (!(isEmptyStack(&TmpStack2)))
		{
			push(&TmpStack1, pop(&TmpStack2));
		}
	}

	while (!(isEmptyStack(&TmpStack1)))
	{
		push(&OriginalStack, pop(&TmpStack1));
	}

	printf("the new string: ");
	while (!(isEmptyStack(&OriginalStack)))
	{
		res = pop(&OriginalStack);
		printf("%c", res);
	}

}

int isPalindrome(Stack* s)
{
	int palindrome = 1;
	int NotPalindrome = 0;
	if (s->head == NULL) {
		printf("stack empti - no word\n");	//������ ����-  �� ����� � ���
		return (NotPalindrome);
	}

	// ������ �� ���� ��� �����
	Stack* HelpStack;		   	 //������ ���
	Stack* Top; 			    	//����� ����
	initStack(&HelpStack);
	initStack(&Top);
	Top->head = s->head;	//����� �� ����

	while (Top->head != NULL)			//���� ������� ����� ������� �� ������� ��� �� ����
	{
		push(HelpStack, (Top->head->data));		// ���� ����� ��� ��������
		Top->head = Top->head->next;  //������ ��� ��� �����
	}
	Top->head = s->head; // ������ ��� ����
	while (Top->head != NULL)
	{

		if (!(pop(&HelpStack)) == (Top->head->data))
			return (NotPalindrome);									 //������ ��� ������� ��� �� ��� ���� �� �� ���� ������ 0 ����� �������

		else
		{
			Top->head = Top->head->next;				 //����� �� ����� �� ��� �� ������. ��� ��� ������ ���� ������� ��� ����
		}
		return(palindrome);   //������ 1 �� ������ �� ��� �� ��� ��������
	}

}

void rotateStack(Stack* s, int n)
{
	// add your code here
}