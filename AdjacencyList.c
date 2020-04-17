
//Adjacency Matrix

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node
{
	int data;
	struct node *next;
}node;

int v;

int e;


node *ptr[30]={NULL};

void makeconnection(int index,int value)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=value;
	temp->next=NULL;
	
	if(ptr[index]==NULL)
	{
		ptr[index]=temp;
	}
	else
	{
		node *p=ptr[index];
		while(p->next)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
	
void display()
{
	int i;
	for(i=0;i<v;i++)
	{
		if(ptr[i]==NULL)
		{
			printf("No element");
		}
		else
		{
			node *p=ptr[i];
			while(p->next)
			{
				printf("%d ",p->data);
				p=p->next;
			}
			printf("%d ",p->data);
			printf("\n");
		}
	}
}
			



int main()
{
	
	printf("Enter the no of vertices");
	scanf("%d",&v);
	
	
	printf("\nEnter the no of edges");
	scanf("%d",&e);
	
	
	
	printf("\nEnter the connection between the edges");
	
	int i;
	
	for(i=0;i<e;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		makeconnection(a,b);
		//makeconnection(b,a);
	}
	
	display();
	return 0;
}	
