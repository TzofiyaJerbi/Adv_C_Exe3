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

	int yuserSelt;
	char d;
	Stack* dugma;
	initStack(&dugma);
	while (1)
	{
		printf("\nTo push word to stack choose 1 \n To check if is palindrome choose 2\n \
To fix word with # choose 3 \n To delaet data choose 4\n To print stack choose 5 \n for rotate World press choose 6\n");

		fseek(stdin, 0, SEEK_END);
		scanf("%d", &yuserSelt);

		switch (yuserSelt)
		{
		case 1:
		{
			
			printf("get leter to stack\n");
			fseek(stdin, 0, SEEK_END);
			scanf("%c", &d);
		    push(&dugma, d);
			break;
		}
		case 2:
		{
			 int Palindrome =isPalindrome(&dugma);
			 if (Palindrome == 1)
				 printf("is Palindrome\n");
			 else
				 printf("is not Palindrome\n");
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
		case 6:
		{
			printf("select place rotate \n");
			int n;
			rotateStack(&dugma, (scanf("%d", &n)));

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