//linked lists

//performing all operations in the linked lists

//insertion deletion insertion at last ...

//push 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int value;
	struct node *next;
}node;


node *head=NULL;

void push(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	
	temp->next=NULL;
	temp->value=ele;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		//inserting at first
		temp->next=head;
		head=temp;
	}
}

void insert_at_last(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	
	temp->next=NULL;
	temp->value=ele;
	
	if(head==NULL)
	{
		head=temp;
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
	}
}

void insert(int pos,int ele)
{
	
	node *temp=(node *)malloc(sizeof(node));
	
	temp->next=NULL;
	temp->value=ele;
	
	
	
	if(pos==1)
	{
		//it means that inserting at pos1
		
		temp->next=head;
		head=temp;
	}
	else
	{
		node *p=head;
		int count=2;
		while(p && count<pos)
		{
			p=p->next;
			count++;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
	

void delete(int pos)
{
		if(pos==1)
		{
			node *temp=head;
			head=temp->next;
			free(temp);
		}
		else
		{
			int count=2;
			node *p=head;
			while(p && count<pos)
			{
				p=p->next;
				count++;
			}
			node *temp=p->next;
			p->next=temp->next;
			free(temp);
		}
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
	push(10); //push in the sense insert at first
	display();
	
	push(20);
	display();
	
	push(30);
	display();
	
	insert_at_last(5);
	display();
	
	insert_at_last(2);
	display();
	
	
	printf("Inserting at the first position the element is 50");
	insert(1,50);
	display();
	
	printf("Inserting at the 3 rd position the element is 60");
	insert(3,60);
	display();
	
	printf("Deleting the element at the first position");
	delete(1);
	display();
	
	printf("Deleting the element at the third position");
	delete(3);
	display();
}
	
	
	
	
