#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

//void flipBetweenHashes(const char* sentence);
//void initStack(Stack* s);
//void destroyStack(Stack* s);
//void push(Stack* s, char data);
//char pop(Stack* s);
//int isEmptyStack(const Stack* s);
//int isPalindrome(Stack* s);
//void rotateStack(Stack* s, int n);
void PrintStack(Stack* s);


//typedef struct charNode
//{
//	char data;
//	struct charNode* next;
//}charNode;
//
//typedef struct Stack
//{
//	charNode* head;
//}Stack;

void main()
{

	int yuserSelt, data;
	Stack* dugma;
	initStack(&dugma);
	while (1)
	{
		printf("\nTo push word to stack chus 1 \n To check if is palindrome chus 2\n \
To fix word with # chus 3 \n To delaet data chus 4\n To print stack chus 5 \n");

		fseek(stdin, 0, SEEK_END);
		scanf("%d", &yuserSelt);

		switch (yuserSelt)
		{
		case 1:
		{
			printf("get leter to stack");
			scanf("%d", &data);
			push(&dugma, data);
			break;
		}
		case 2:
		{
			isPalindrome(&dugma);
			break;
		}
		case 3:
		{
			char str[] = { "remem#reb#" };
			flipBetweenHashes(str);
			//flipBetweenHashes(const char* sentence)
			break;
		}
		case 4:
		{
			destroyStack(&dugma);
			break;
		}
		case 5:
		{
			PrintStack(&dugma);
			break;
		}
		default:
			printf("\nwrong chus try again \n ");
			break;
		}
	}
}
void PrintStack(Stack* s) {

	if (s->head == NULL)
	{
		printf("Empty stack\n");
		return 0;
	}
	Stack* Top = (Stack*)malloc(sizeof(Stack));    //מצביע לראש
	if (Top == NULL) //בדיאה אם ההקצאה נכשלה
	{
		printf("no memory!!\n");
		return;
	};
	Top->head = s->head;
	while (Top->head != NULL)	//	עובר אות אות ומדפיס	
	{
		printf("%c", Top->head->data);
		Top->head = Top->head->next;
	}

}