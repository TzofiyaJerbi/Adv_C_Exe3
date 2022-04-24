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

	Stack* Top = (Stack*)malloc(sizeof(Stack));    //������� ���
	if (Top == NULL) //����� �� ������ �����
	{
		printf("no memory!!\n");
		return;
	};
	Stack* Top2 = (Stack*)malloc(sizeof(Stack));
	if (Top2 == NULL) //����� �� ������ �����
	{
		printf("no memory!!\n");
		return;
	};
	Top->head = s->head;   //������� ����
	Top2->head = s->head;
	int count = 1;   // ���� ��� �����
	while (Top->head->next != NULL)	//���� ����		
	{
		count++;
		Top->head = Top->head->next;
	}
	Top->head = s->head;

	for (count; count > 0; count--)
	{
		for (int Dcount = (count-1 ); Dcount > 0; Dcount--) {
			Top2->head = Top2->head->next;
		}

		if ((Top->head->data) != (Top2->head->data))
			return(NotPalindrome);
		Top->head = Top->head->next;  // ���� ����� �� ��� ����
		Top2->head = s->head;
	}
	return(palindrome);
}

void rotateStack(Stack* s, int n)
{
	if ((isEmptyStack(&s))); return;
	if (n < 0 || n>(LongOfWord(&s)))return; //����� �� �� ����� ���� ����� �������
	

	Stack helpstack, helpstack2, finalStack;    //������� ��� ����� ����
	
	initStack(&helpstack);
	initStack(&helpstack2);
	finalStack.head = s->head;
	int partLeft =((LongOfWord(&s))-n);

	for (partLeft; partLeft > 0; partLeft--)
	{
		push(&helpstack, (pop(&finalStack))); // ���� ��� ����� �� �����
	}
	while (&finalStack)
	{
		push(&helpstack2, (pop(&finalStack)));
	}
	while (&helpstack) // ��� ���- ����� ���� �� �����- ��� ��� �����
	{
		push(&finalStack, (pop(&helpstack)));
	}
	while (&helpstack2)
	{
		push(&finalStack, (pop(&helpstack2)));
	}
	s->head = finalStack.head;
	printf("the rotate stack is:\n");
	PrintStack(&s);
}

int LongOfWord(Stack* s)
{
	int count = 1; //����� ���� ��� �����. �� �� ��� �� �� ���� ���... 
	Stack* Top = (Stack*)malloc(sizeof(Stack));    //������� ���
	if (Top == NULL) //����� �� ������ �����
	{
		printf("no memory!!\n");
		return;
	};
	Top->head = s->head;
	while (Top->head->next)	//���� ����		
	{
		count++;
		Top->head = Top->head->next;
	}
	return (count);
}
