//hashing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct hashing
{
	int data;
	struct hashing *next;
}hashing;

hashing *ptr[10]={NULL},*temp;


void insert()
{
	printf("Enter the value that u want to insert");
	int value;
	scanf("%d",&value);
	
	int index=(value)%10;
	
	temp=(hashing *)malloc(sizeof(hashing));
	temp->data=value;
	temp->next=NULL;
	
	if(ptr[index]==NULL)
	{
		ptr[index]=temp;
	}
	else
	{
		hashing *p=ptr[index];
		while(p->next)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
	
void print()
{
	int i;
	for(i=0;i<10;i++)
	{
		if(ptr[i]==NULL)
		{
			printf("No element");
		}
		else
		{
			hashing *c;
			for(c=ptr[i];c!=NULL;c=c->next)
			{
				printf("%d ",c->data);
			}
		}
		printf("\n");
	}
}
			
	
	



void main()
{
	int n;
	printf("Enter how many elements do u want to insert");
	scanf("%d",&n);
	
	int i;
	
	for(i=0;i<n;i++)
	{
		insert();
	}
	print();
}

