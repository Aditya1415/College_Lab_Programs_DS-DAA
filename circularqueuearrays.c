//circular queue using arrays

//circular queues can be done using arrays easily

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int start=-1,rear=-1;

int *circularqueue;

int size;

void push(int ele)
{
	if((rear+1)%size !=start)
	{
		rear=(rear+1)%size;
		*(circularqueue + rear)=ele;
	}
	else
	{
		printf("The Queue is full");
	}
}

void pop()
{
	if(rear==0|| rear==start)
	{
		printf("The Queue is empty");
	}
	else
	{
		start=(start+1)%size;
	}
}

int top()
{
	if(start==rear)
	{
		return -1;
	}
	else
	{
	return *(circularqueue+((start+1)%size));
	}
}

void display()
{
	int i;
	printf("\n");
	for(i=(start+1)%size ;(i+1)%size !=start;i++)
	{
		printf("%d ",*(circularqueue+i));
	}
	printf("\n");
}
	


void main()
{
	printf("Enter the size of the circular queue that u want to have");
	scanf("%d",&size);
	
	//allocating the space for the circular queue
	
	circularqueue=(int *)calloc((size) , sizeof(int));
	//should allocate one extra box ....
	
	push(10);
	display();
	
	push(20);
	display();
	
	push(30);
	display();
	
	pop();
	display();
	
	printf("\nThe front element is %d ",top());
	
	push(40);
	display();
	
	push(50);
	display();
	
	pop();
	display();
	
	printf("\nThe front element is %d ",top());
}
	
	
	


