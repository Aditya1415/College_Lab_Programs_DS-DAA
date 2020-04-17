//circular queue

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>



int *ptr;

int n;

int f=0;
int r=0;

void push(int ele)
{
	if(((r+1)%n)!=f)  //if (r+1)%n==f queue is full 
	{
		r=((r+1)%n);
		*(ptr+r)=ele;
	}
	else
	{
		printf("Queue is full");
	}
}

void pop()
{
	if(f==r)
	{
		printf("Queue is empty");
	}
	else
	{
		f=(f+1)%n;
		printf("\nThe deleted element is  %d\n",*(ptr+f));
	}
}

void display()
{
	int i;
	printf("\n");
	for(i=(f+1)%n ;((i+1)%n)!=f;i++)
	{
		printf("%4d",*(ptr+i));
	}
}

	
	



int main()
{
	printf("Enter the size of the circular queue");
	scanf("%d",&n);
	
	ptr=(int *)malloc(((n+1)*sizeof(int)));
	
	
	push(10);
	display();
	push(20);
	display();
	push(30);
	display();
	push(40);
	display();
	push(50);
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	push(60);
	push(70);
	display();
}
	
	
	
	
	