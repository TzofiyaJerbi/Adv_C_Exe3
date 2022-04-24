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
void printQueue(Queue* q);
void mainOFstack();
void mainOFqueue();
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

	while (1)
	{
		printf("which mood U want to check?\n choose 1 to stack \n choose 2 to queue\n");
		int yuserSelt;
		scanf("%d", &yuserSelt);
		if (yuserSelt == 1)
			mainOFstack();
		else
		{
			if (yuserSelt == 2)
				mainOFqueue();

			else
			{
				if ((yuserSelt != 1) || (yuserSelt != 2))
					printf("\nwrong chus try again \n ");

			}
		}
	}
	
}


void mainOFstack()
{
	
	int yuserSelt;
	char d;
	Stack dugma;
	initStack(&dugma);
	while (1)
	{
		printf("\nTo push word to stack choose 1 \n To check if is palindrome choose 2\n \
To fix word with # choose 3 \n To delaet data choose 4\n To print stack choose 5 \n for rotate World press choose 6\n \
to delete word from top stack choose 7\n to exit choose 8\n");

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
			int n ;
			scanf("%d", &n);
			rotateStack(&dugma, n);
			break;
		}
		case 7:
		{
			char LetterPop;
			LetterPop = pop(&dugma);
			printf("the letter is pop is %c", LetterPop);
			break;
		}
		case 8:
		{
			exit(1);
		}
		default:
			printf("\nwrong chus try again \n ");
			break;
		}
	}
}


void mainOFqueue()
{
	Queue myQueue;
	initQueue(&myQueue);
	while (1)
	{
		printf("\nto add data to queue choose 1\n to delete queue choose 2\n \
 to delete first valu choose 3\n to rotate choose 4\n \
 to cut and replace choose 5\n to sort queue choose 6\n to print queue choose 7\n to exit choose 8\n");
		int yuserSelt;
		scanf("%d", &yuserSelt);

		switch (yuserSelt)
		{
		case 1:
		{
			
				printf("choose data to add\n");
				unsigned data;
				scanf("%d",&data);
				enqueue(&myQueue , data);
			
			break;
		}
		case 2:
		{
			destroyQueue(&myQueue);
			break;
		}
		case 3:
		{
			dequeue(&myQueue);
			break;
		}
		case 4:
		{
			rotateQueue(&myQueue);
			break;
		}
		case 5:
		{
			cutAndReplace(&myQueue);
			break;
		}
		case 6:
		{
			sortKidsFirst(&myQueue);
			break;
		}
		case 7:
		{
			printQueue(&myQueue);
			break;
		}
		case 8:
		{
			exit(1);
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
	
	charNode* Top = s->head;
	while (Top != NULL)	//	עובר אות אות ומדפיס	
	{
		printf("%c", Top->data);
		Top = Top->next;
	}

}

void printQueue(Queue* q)
{
	if (isEmptyQueue(q))
	{
		printf("empti queue");
	return;
	}
	else
	{
		Queue Qtmp;
		initQueue(&Qtmp);
		unsigned data;
		while (! isEmptyQueue(q))
		{
			data = dequeue(q);
			printf("%d", data);
			enqueue(&Qtmp, data);
		}
		while (! isEmptyQueue(&Qtmp))
		{
			enqueue(q, dequeue(&Qtmp));
		}
	}

	}