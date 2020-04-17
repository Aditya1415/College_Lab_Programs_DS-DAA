//binary search tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}node;


node *root=NULL;

void insert(int ele)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=ele;
	temp->lchild=NULL;
	temp->rchild=NULL;
	
	node *p=root;
	
	node *pp=NULL;
	
	while(p)
	{
		pp=p;
		if(p->data < ele)
		{
			p=p->rchild;
		}
		else if(p->data >ele)
		{
			p=p->lchild;
		}
	}
	if(p==root)
	{
		root=temp;
	}
	else
	{
		if(pp->data < ele)
		{
			pp->rchild=temp;
		}
		else
		{
			pp->lchild=temp;
		}
	}
}

void inorder(node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}

void preorder(node *p)
{
	if(p)
	{
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void postorder(node *p)
{
	if(p)
	{
		
		preorder(p->lchild);
		preorder(p->rchild);
		printf("%d ",p->data);
	}
}
	
void delete(int ele)
{
		//first search for the element
		
		node *p=root;
		node *pp=NULL;
		node *c=NULL;
		node *pc=NULL;
		while(p && p->data !=ele)
		{
			pp=p;
			if(p->data <ele)
			{
				p=p->rchild;
			}
			else if(p->data >ele)
			{
				p=p->lchild;
			}
		}
		if(!p)
		{
			printf("there is no such element");
		}
		else
		{
			if(p->lchild && p->rchild)
			{
				//so take the left most child of the right child or the right most child of the lchild
				
				c=p->rchild;
				
				while(c->lchild)
				{
					pc=c;
					c=c->lchild;
				}
				
				//now swap the values of the child and the p
				
				p->data=c->data;
				
				p=c;
				pp=pc;
			}
			if(p->lchild)
			{
				c=p->lchild;
			}
			if(p->rchild)
			{
				c=p->rchild;
			}
			if(p==root)
			{
				root=c;
			}
			else
			{
				if(p==pp->lchild)
				{
					pp->lchild=c;
				}
				else
				{
					pp->rchild=c;
				}
			}
		}
}

void main()
{
	insert(10);
	inorder(root);
	printf("\n");
	
	insert(20);
	inorder(root);
	printf("\n");
	
	insert(50);
	inorder(root);
	printf("\n");
	
	insert(30);
	inorder(root);
	printf("\n");
	
	insert(60);
	inorder(root);
	printf("\n");
	
	insert(5);
	inorder(root);
	printf("\n");
	
	preorder(root);
	printf("\n");
	
	postorder(root);
	printf("\n");
	
	delete(30);
	inorder(root);
	printf("\n");
	
	delete(20);
	inorder(root);
	printf("\n");
}
	
		

