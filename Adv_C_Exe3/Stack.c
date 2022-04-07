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
	if (pointerToHead) {//בדיאה אם ההקצאה לא נכשלה 

		while ((s->head) != NULL)
		{
			pointerToHead = (s->head);
			s->head = s->head->next;
			free(pointerToHead);
		} printf("success! naw the stack is empty \n");
	}
	else //הקצאה נכשלה
	{
		printf("can't destroy Stack\n ");
	}
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL) //בדיאה אם ההקצאה נכשלה
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
	if (isEmptyStack(s))		// כאשר מחסנית ריקה חוזר אחד ו- יתקיים התנאי 
	{
		printf("the stack is empty\n");
		exit(1);
	}

	char res = s->head->data;			//  מחסנית לא ריקה, שליפת מידע, עדכון הטופ ושחרור מקום הראשון
	charNode* tmp = s->head;
	s->head = s->head->next;
	free(tmp);
	return res;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;				// מחזיר 1: אמת, מצביע לאיבר0  מחסנית ריקה
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
		push(&OriginalStack, sentence[i]);//דוחף את המשפט למחסנית
		i--;
	}

	while (!(isEmptyStack(&OriginalStack)))//כל עוד המחסנית לא ריקה
	{
		while (1)
		{
			res = pop(&OriginalStack);//מוציאים תו תו
			if (res == '#')//בדיקה אם הגענו ל#
				break;
			push(&TmpStack1, res);//מחסנית עזר1
		}


		while (1)
		{
			if (isEmptyStack(&OriginalStack))
				break;
			res = pop(&OriginalStack);
			if (res == '#')
				break;

			push(&TmpStack2, res);//מחסנית עזר2
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
		printf("stack empti - no word\n");	//מחסנית ריקה-  אם מצביע ל נאל
		return (NotPalindrome);
	}

	// מחסנית עם איבר אחד ומעלה
	Stack* HelpStack;		   	 //מחסנית עזר
	Stack* Top; 			    	//מצביע לראש
	initStack(&HelpStack);
	initStack(&Top);
	Top->head = s->head;	//לשמור על הראש

	while (Top->head != NULL)			//לשים במחסנית ערכים מהרשימה עד שמגיעים לנל לא כולל
	{
		push(HelpStack, (Top->head->data));		// הטופ מתקדם כבר בפונקציה
		Top->head = Top->head->next;  //קידמנו אות אחת קדימה
	}
	Top->head = s->head; // לוקחים ראש מחדש
	while (Top->head != NULL)
	{

		if (!(pop(&HelpStack)) == (Top->head->data))
			return (NotPalindrome);									 //להשוות פופ ממחסנית עזר עם ראש דאטה אם לא שווה להחזיר 0 ולצאת מהלולאה

		else
		{
			Top->head = Top->head->next;				 //מתבצע אם התנאי על איפ לא מתקיים. קרי אות אחרונה שווה לראשונה וכן הלאה
		}
		return(palindrome);   //להחזיר 1 אם מגיעים עד שלב זה קרי פילנדרום
	}

}

void rotateStack(Stack* s, int n)
{
	// add your code here
}