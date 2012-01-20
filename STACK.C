//--------------Write a program to simulate stack-------------
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
int data;
struct stack* next;
};
//....Declaring node

struct stack* first='\0';
struct stack* push(struct stack*,int); // Declaring methods
struct stack* pop(struct stack*);
void show(struct stack* );
//-----------------------
int p=1,q=1; // Global variable
//-----------------------

struct stack* push(struct stack* first,int no)
{
	struct stack* node;
	node=(struct stack*)malloc(sizeof(struct stack)); //DYNEMIC MEMORY ALLOCATION
	if(node=='\0')
	{
		printf("\n THERE IS NO FREE SPACE");
		return node;
	}
	else
	{
		node->data=no;
		node->next='\0';
		struct stack* tmp;
		tmp=(struct stack*)malloc(sizeof(struct stack));
		if(first=='\0')
		{
			first=node;
			return first;
		}
		tmp=first;
		while(tmp->next!='\0')
		{
			tmp=tmp->next;
		}
		tmp->next=node;

	}
return first;
}
//-------------------------------------------
struct stack* pop(struct stack* first)
{
	struct stack* tmp;
	tmp=(struct stack*)malloc(sizeof(struct stack));
	struct stack* previous;
	previous=(struct stack*)malloc(sizeof(struct stack));
	tmp=first;
	if(first=='\0')
	{
		printf("\n STACK IS EMPTY");
		return first;
	}

	else if(first->next=='\0')
	{
		q--;
		first='\0';
		printf("\n POP(%d):%d",q,tmp->data);
		return first;
	}
	while(tmp->next!='\0')
	{
		previous=tmp;
		tmp=tmp->next;
	}
	q--;
	printf("\nPOP(%d):%d",q,tmp->data);
	previous->next='\0';
	return first;
}
//-------------------------------------------
void show(struct stack* first)
{
	int p=1;
	struct stack* tmp;
	tmp=(struct stack*)malloc(sizeof(struct stack));
	tmp=first;
	if(first=='\0')
	{
		printf("\n STACK IS EMPTY");
	}
	while(tmp!='\0')
	{
		printf("\nPUSH(%d)=%d",p,tmp->data);
		tmp=tmp->next;
		p++;
	}
}
//---------------------------------------------------

void main()
{
	int choice,no;
	clrscr();
	do
	{
		printf("\n ------MENU-----\n     1) PUSH\n     2) POP\n     3) SHOW\n     4) EXIT\n ENTER YOUR CHOICE:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n PUSH(%d):",p);
				scanf("%d",&no);
				first=push(first,no);
				p++;
				q=p;
				break;
			case 2:
				first=pop(first);
				break;
			case 3:
				show(first);
				break;
			case 4:
				exit(0);
			default :
				printf("\n sorry..This is not a valid choice ");
		}
	}while(choice!=4);
	getch();
}


