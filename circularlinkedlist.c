//circular linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node
{
	int data;
	struct node *next;
}node;


node *head=NULL;

void insert_at_last(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
		head->next=head;
	}
	else
	{
		node *p=head;
		while(p->next !=head)
		{
			p=p->next;
		}
		p->next=temp;
		temp->next=head;
	}
}
void insert_at_first(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->next=head;
	node *p=head;
	while(p->next !=head)
	{
		p=p->next;
	}
	p->next=temp;
	head=temp;
}
	

void display()
{
	node *p=head;
	printf("\n");
	while(p->next!=head)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);
	printf("\n");

}

void insert(int pos,int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->next=NULL;
	int count=2;
	node *p=head;
	while(p && count<pos)
	{
		count++;
		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;
}

void delete(int pos)
{
	if(pos==1)
	{
		node *p=head;
		node *temp=head;
		while(p->next!=head)
		{
			p=p->next;
		}emai
		p->next=temp->next;
		head=temp->next;
		free(temp);
	}
	else
	{
		int count=2;
		node *p=head;
	while(p && count<pos)
	{
		count++;
		p=p->next;
	}
	node *temp=p->next;
	p->next=temp->next;
	free(temp);
	}
}
		



void main()
{
	insert_at_last(10);
	display();
	
	insert_at_last(20);
	display();
	
	insert_at_first(5);
	display();
	
	insert_at_first(2);
	display();
	
	insert_at_last(30);
	display();
	
	//inserting at specified positions
	
	printf("Inserting element 15 at position 4\n");
	insert(4,15);
	display();
	
	printf("Deleting the 4 th position element\n");
	delete(4);
	display();
	
	printf("Deleting the first position element\n");
	delete(1);
	display();
	
}
	
	
	
	
	

