#include<stdio.h>
#include<conio.h>
struct node
{
int no;
struct node *next;
}*first,*temp,*temp1,*curr,*new1;
void create();
void insert1();
void insert2();
void insert3();
void delete1();
void delete2();
void delete3();
void display();
void main()
{
char ch;
int choice;
//
//int ch;
int option=1;
do
{
clrscr();
printf("\n 1.insert1");
printf("\n 2.insert2");
printf("\n 3.insert3");
printf("\n 4.delete1");
printf("\n 5.delete2");
printf("\n 6.delete3");
printf("\n 7.display");
printf("\n 8.exit");
printf("\n enter your choice");
scanf("%d",&choice);
switch(choice)
{
    case 1:insert1();
    break;
    case 2:insert2();
    break;
    case 3:insert3();
    break;
    case 4:delete1();
    break;
    case 5:delete2();
    break;
    case 6:delete3();
    break;
    case 7:display();
    break;
    case 8:exit();
    break;
    default:printf("\n enter correct option");
}
printf("\n do you want to continue?y/Y\t");
flushall();
scanf("%c",ch);

}
/*while(ch=='y'||ch=='Y');
getch();
} */
while(option);
getch();
}
void create()
{
   new1=(struct node*)malloc(sizeof(struct node));
   printf("\n enter the data");
   scanf("%d",&new1->no);
   new1->next=NULL;
}

void insert1()
{
   create();
   if(first==NULL)
     {
       first=new1;
     }
   else
   {
     new1->next=first;
     first=new1;
   }
   printf("\n node is inserted");
   display();
}
void insert2()
{
  create();
  if(first==NULL)
    {
      first=new1;
    }
  else
  {
     curr=first;
     while(curr->next!=NULL)
     {
	curr=curr->next;
     }
     curr->next=new1;
  }
  printf("\n node is inserted2");
  display();

}

void insert3()
{
int pos,i=1;
printf("\n enter pos:");
scanf("%d",&pos);
create();
if(first==NULL)
{
  first=new1;
  }
else
{
  curr=first;
  while(i<pos-1)
  {
    curr=curr->next;
    i++;
  }
  new1->next=curr->next;
  curr->next=new1;
}
printf("\n node is inserted3...");
display();

}

void delete1()
{
  if(first==NULL)
  printf("LL is EMPTY:");
  else
  {
   temp=first;
   first=first->next;
   free(temp);
   display();
  }
}

void delete2()
{
  if(first==NULL)
  printf("LL is EMPTY:");
  else
  {
   temp=first;
   while(temp->next->next!=NULL)
   {
   temp=temp->next;
   free(temp);
   display();
  }
  }
}

void delete3()
{
int pos,i=1;
printf("\n enter the pos");
scanf("%d",&pos);
curr=first;
while(i<pos-1)
{
printf("\n %d",curr->no);
curr=curr->next;
i++;
}
{
  temp1=curr->next;
  curr->next=temp1->next;
  temp=curr->next;
  free(temp);
  }
printf("\n node is deleted3");
display();
}


void display()
{
  curr=first;
  printf("\n nodes are...");
  while(curr!=NULL)
  {
    printf("\t %d",curr->no);
    curr=curr->next;
  }
}
