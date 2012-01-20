#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
char name[50];
struct node *next;
};

struct node *first=NULL;
struct node *new1;
struct node *temp;

void eliminate(int position)
{
  int i=0;
  struct node *prev;
  if(first==NULL)
  {
	printf("\n\tThere is no Player to Eliminated");
       goto a;
  }

  if(position==0)
  { printf("\n\n=====>>>>%d) %s is Eliminated\n",position+1,first->name);
    temp=first->next;
    while(temp!=first)
    {
      prev=temp;
      temp=temp->next;
    }
    prev->next=temp->next;
    first=prev->next;
  }
  else
  {
    temp=first;
    for(i=0;i<position;i++)
    {
      prev=temp;
      temp=temp->next;
    }
    prev->next=temp->next;
    printf("\n-------->%d) %s is Eliminated",position+1,temp->name);
    first=prev->next;
  }
   a:
}

void add(char na[])
{
  new1=(struct node*)malloc(sizeof(struct node));
  if(new1==NULL)
  { printf("\nNo free space available\n");
    exit(0);
  }
  strcpy(new1->name,na);
  new1->next=new1;

  if(first==NULL)
  {
    first=new1;
  }

  else
  {
     temp=first->next;

     while(temp->next!=first)
     {
	temp=temp->next;
     }
     new1->next=temp->next;
     temp->next=new1;
   }
}
//------------------------

void print()
{  int i=2;
    if(first==NULL)
   { printf("\n\tThere No Player");
     goto a;
   }

   else
   {
    printf("\n1) %s",first->name);
    temp=first->next;
    while(temp!=first)
    {
      printf("\n%d) %s ",i,temp->name);
      temp=temp->next;
      i++;
    }
   }
   a:
}

void main()
{
  int choice,num,i,delet;
  char ch[50];

  clrscr();

  while(choice!=4)
  {
   if(first->next==first)
   {
   printf("\n\n\n\nCongratulation \t\%s Won The Game",first->name);
   goto a;
   }
   printf("\n\n*****MENU*****\n1)Add:-""\n2)Delete:-""\n3)Print:-""\n4)Exit");
   printf("\nENTER YOUR CHOICE:");
   scanf("%d",&choice);


   switch(choice)
   {
    case 1:printf("\nEnter Total number OF Player:");
	   scanf("%d",&num);
	   for(i=1;i<=num;i++)
	   {
		   printf("\nENTER NAME:");
		   flushall();
		   gets(ch);
		   add(ch);
	   }

	   break;
    case 2: delet=random(num);
	    eliminate(delet);
	    num=num-1;
	    break;
    case 3: flushall();
	    print();
	    printf("\n");
	    break;
    case 4: exit(0);
	    break;
    default:printf("\n.......This is not a valid choice:");
   }
  }
  a:
  getch();
}

