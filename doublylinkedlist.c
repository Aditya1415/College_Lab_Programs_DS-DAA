//doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *previous;
	struct node *next;
}node;

node *head=NULL,*rear=NULL;

void push(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->previous=NULL;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
		rear=temp;
	}
	else
	{
		//push function means inserting at the first
		
		temp->next=head;
		head->previous=temp;
		head=temp;
	}
}

void insert_at_last(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->previous=NULL;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
		rear=temp;
	}
	else
	{
		//inserting at the last
		node *p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=temp;
		p=temp;
		rear=p;
	}
}

void insert(int pos,int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->previous=NULL;
	temp->next=NULL;
	if(pos==1)
	{
				
		temp->next=head;
		head->previous=temp;
		head=temp;
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
		if(!p)
		{
			printf("This element cannot be inserted at the specified position");
		}
		else
		{
			p->next->previous=temp;
			temp->next=p->next;
			temp->previous=p;
			p->next=temp;
		}
	}
}

void delete(int pos)
{
	if(pos==1)
	{
		node *temp=head;
		head=temp->next;
		head->previous=NULL;
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
		if(!p)
		{
			printf("This element cannot be deleted at the specified position");
		}
		else
		{
			node *temp=p->next;
			//temp is the node that we wanted to delete
			p->next=temp->next;
			temp->next->previous=p;
			free(temp);
			
		}
	}
	
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
	push(10);
	display();
	
	insert_at_last(20);
	display();
	
	insert_at_last(30);
	display();
	
	push(5);
	display();
	
	push(2);
	display();
	
	printf("Inserting element at pos 4 i.e 15");
	insert(4,15);
	display();
	
	printf("Inserting element at pos 5 i.e 18");
	insert(5,18);
	display();
	
	printf("Inserting the element at pos 1 i.e 1");
	insert(1,1);
	display();
	
	printf("Deleting the 4 th element");
	delete(4);
	display();
	
	printf("Deleting the 1 st element");
	delete(1);
	display();
}
	
	
	
	
	