//reverse a linked list

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}node;


node *head=NULL;

void insert(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->next=NULL;
	temp->data=ele;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
		
void reverse()
{
	
	node *current=head;
	node *previous=NULL;
	node *nextnode=NULL;
	
	while(current)
	{
		nextnode=current->next;
		current->next=previous;
		previous=current;
		current=nextnode;
	}
	head=previous;


}


void display()
{
	node *p=head;
	printf("\n");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}



void main()
{
		insert(10);
		display();
		
		insert(20);
		display();
		
		insert(30);
		display();
		
		insert(40);
		display();
		
		insert(50);
		display();
		
		insert(60);
		display();
		
		insert(70);
		display();
		
		reverse();
		display();
}