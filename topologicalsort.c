//topological sort


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

int indegree[30]={0};

int queue[30];

int start=0,rear=0;

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
	
void indegreecal()
{
	int i;
	//calculate indegree
	for(i=0;i<v;i++)
	{
		if(ptr[i]==NULL)
		{
			continue;
		}
		else
		{
			node *p=ptr[i];
			while(p)
			{
				(indegree[p->data])++;
				p=p->next;
			}
			
		}
	}
	
	//need to add to the queue the vertices which have indegree 0
	
	for(i=0;i<v;i++)
	{
		if(indegree[i]==0)
		{
			queue[rear]=i;
			rear++;
		}
	}	
		
}
	
	
void displayindegree()
{
	int i;
	printf("Indegrees of the vertices");
	for(i=0;i<v;i++)
	{
		printf("%d ",indegree[i]);
	}
}
	
void displayqueue()
{
	int i;
	
	printf("\n\nQueue diaplaying");
	
	for(i=0;i<rear;i++)
	{
		printf("%d ",queue[i]);
	}

}

void topologicalsort()
{
	//queue is insertion at last and deletion at first
	
	printf("\n\n Printing the topological way");
	while(start!=rear)
	{
		int ele=queue[start];
		start++;
		
		node *p=ptr[ele];
		
		while(p)
		{
			int vertice=p->data;
			indegree[vertice]--;
			p=p->next;
			if(indegree[vertice] ==0)
			{
				queue[rear]=vertice;
				rear++;
			}
		}
		
		printf("%d ",ele);
		
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
	
	printf("\n");
	
	indegreecal();
	
	displayindegree();
	
	displayqueue();
	
	topologicalsort();
	
	return 0;
}	
