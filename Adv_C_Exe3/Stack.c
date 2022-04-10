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

	Stack* Top = (Stack*)malloc(sizeof(Stack));    //מחסניות עזר
	if (Top == NULL) //בדיאה אם ההקצאה נכשלה
	{
		printf("no memory!!\n");
		return;
	};
	Stack* Top2 = (Stack*)malloc(sizeof(Stack));
	if (Top2 == NULL) //בדיאה אם ההקצאה נכשלה
	{
		printf("no memory!!\n");
		return;
	};
	Top->head = s->head;   //מצביעים לראש
	Top2->head = s->head;
	int count = 1;   // איבר אחד לפחות
	while (Top->head->next != NULL)	//אורך מילה		
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
		Top->head = Top->head->next;  // מכין מיקום של אות הבאה
		Top2->head = s->head;
	}
	return(palindrome);
}

void rotateStack(Stack* s, int n)
{
	charNode* Ps = s->head;
//	if (!(isEmptyStack(Ps))); return;
	if (n < 0 || n>(LongOfWord(&Ps)))return; //ממשיך רק אם חיובי וקטן מאורך המחסנית
	


	Stack* helpstack = (Stack*)malloc(sizeof(Stack));    //מחסנית עזר לחלקי מילה
	if (helpstack == NULL) //בדיאה אם ההקצאה נכשלה
	{
		printf("no memory!!\n");
		return;
	};
	initStack(&helpstack);

	Stack* finalStack = (Stack*)malloc(sizeof(Stack));  // מחסנית למילה סופית מסודרת
	if (finalStack == NULL) //בדיאה אם ההקצאה נכשלה
	{
		printf("no memory!!\n");
		return;
	};
	initStack(&finalStack);

	int partLeft =( LongOfWord(&Ps)-n);


	for (partLeft; partLeft > 0; partLeft--)
	{
		push(helpstack, (pop(&Ps))); // שומר חלק פנימי של המילה

	}
	while (helpstack)
	{
		push(finalStack, (pop(&helpstack)));
	}
	while (Ps) // ראש אחר- במקום האני של המילה- ועד סוף המילה
	{
		push(helpstack, (pop(&Ps)));
	}
	while (helpstack)
	{
		push(finalStack, (pop(&helpstack)));
	}

	PrintStack(&Ps);


	//יש לכתוב את הפונקציה בהנחה ש אנ הוא ערך במחסנית, ולבצע היפוך, אולי לולאה מקוננת?
}

int LongOfWord(Stack* s)
{
	int count = 1; //לפחות איבר אחד במילה. אם זה אפס זה לא מגיע לפה... 
	Stack* Top = (Stack*)malloc(sizeof(Stack));    //מחסניות עזר
	if (Top == NULL) //בדיאה אם ההקצאה נכשלה
	{
		printf("no memory!!\n");
		return;
	};
	Top->head = s->head;
	while (Top->head->next)	//אורך מילה		
	{
		count++;
		Top->head = Top->head->next;
	}
	return (count);
}
