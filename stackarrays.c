//stack using arrays

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
	int data;
}stack;

stack *ptr;

int top=-1;

int n;

void push(int ele)
{
	top++;
	(ptr+top)->data=ele;
}

void pop()
{
	top--;
}

void display()
{
	int x=top;
	printf("\n");
	for(x=top;x>=0;x--)
	{
		printf("%d ",(ptr+x)->data);
	}
	printf("\n");
}


void main()
{
	printf("Enter the size of the matrix");
	
	scanf("%d",&n);
	
	//alllocating the space for the stack
	
	ptr=(stack *)malloc(n * sizeof(stack));
	
	push(10);
	display();
	
	push(20);
	display();
	
	push(30);
	display();
	
	push(40);
	display();
	
	pop();
	display();
	
	pop();
	display();
}