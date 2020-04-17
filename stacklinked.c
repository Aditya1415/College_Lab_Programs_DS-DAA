//stacks using linked list

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//stack means insert at first and delete at first


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
		
		pop();
		display();
		
		pop();
		display();
		
		pop();
		display();
		
		pop();
		display();
		
		insert(60);
		display();
		
		insert(70);
		display();
		
		pop();
		display();
}