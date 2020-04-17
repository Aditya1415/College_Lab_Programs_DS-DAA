//queues

//queue can be divide into two types i.e normal queue and circular queue

//normal queue using linked list for that we need to have two pointers front and rear

//queue is deleting at first inserting at last

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int value;
	struct node *next;
}node;


node *head=NULL,*rear=NULL;

void push(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	
	temp->next=NULL;
	temp->value=ele;
	
	if(head==NULL)
	{
		head=temp;
		rear=temp;
	}
	else
	{
		//inserting at last
		node *p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=temp;
		rear=temp;
	}
}

void pop()
{
	node *temp=head;
	head=temp->next;
	free(temp);
}

void display()
{
	node *p=head;
	printf("\n");
	while(p)
	{
		printf("%d ",p->value);
		p=p->next;
	}
	printf("\n");
}

void main()
{
	push(10);
	display();
	
	push(20);
	display();
	
	pop();
	display();
	
	push(30);
	display();
	
	push(40);
	display();
	
	pop();
	display();
}

