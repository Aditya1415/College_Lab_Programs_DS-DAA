#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coe;
	int deg;
	struct node * next;
}node;

node *head1=NULL;
node *head2=NULL;
node *result=NULL;

void add()
{
	node *p=head1;
	node *q=head2;
	node *r=result;
	while(p && q)
	{
		node *temp=(node *)malloc(sizeof(node));
		if(p->deg>q->deg)
		{
			temp->coe=p->coe;
			temp->deg=p->deg;
			temp->next=NULL;
			p=p->next;
		}
		else if(p->deg<q->deg)
		{
			temp->coe=q->coe;
			temp->deg=q->deg;
			temp->next=NULL;
			q=q->next;
		}
		else
		{
			temp->coe=p->coe+q->coe;
			temp->deg=p->deg;
			p=p->next;
			q=q->next;
		}
		if(!result)
		{
			result=r=temp;
		}
		else
		{
			r->next=temp;
			r=r->next;
		}
	}
	while(p)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->coe=p->coe;
		temp->deg=p->deg;
		temp->next=NULL;
		p=p->next;
		if(!result)
		{
			result=r=temp;
		}
		else
		{
			r->next=temp;
			r=r->next;
		}
	}
	while(q)
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->coe=q->coe;
		temp->deg=q->deg;
		temp->next=NULL;
		q=q->next;
		if(!result)
		{
			result=r=temp;
		}
		else
		{
			r->next=temp;
			r=r->next;
		}
	}
	
}

void main()
{
	int n[2],i,j,co,de;
	for(i=0;i<2;i++)
	{
		printf("enter no.of terms in %dst",(i+1));
		scanf("%d",&n[i]);
		for(j=0;j<n[i];j++)
		{
			printf("enter coe");
			scanf("%d",&co);
			printf("enter deg");
			scanf("%d",&de);
			if(i==0)
			{
				node *temp=(node *)malloc(sizeof(node));
				temp->coe=co;
				temp->deg=de;
				temp->next=NULL;
				if(!head1)
				{
					head1=temp;
				}
				else
				{
					node *p=head1;
					while(p->next)
					{
						p=p->next;
					}
					p->next=temp;
				}
			}
			else
			{
				node *temp=(node *)malloc(sizeof(node));
				temp->coe=co;
				temp->deg=de;
				temp->next=NULL;
				if(!head2)
				{
					head2=temp;
				}
				else
				{
					node *p=head2;
					while(p->next)
					{
						p=p->next;
					}
					p->next=temp;
				}
			}
		}
	}
	node *q=head1;
	while(q)
	{
		printf("%dx^%d  ",q->coe,q->deg);
		q=q->next;
	}
	printf("\n");
	node *r=head2;
	while(r)
	{
		printf("%dx^%d ",r->coe,r->deg);
		r=r->next;
	}
	printf("\n");
	add();
	node*p=result;
	while(p)
	{
		printf("%dx^%d  ",p->coe,p->deg);
		p=p->next;
	}
}