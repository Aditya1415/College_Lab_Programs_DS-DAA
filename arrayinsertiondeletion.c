//external practice

//pgm 1 insertion of elements into an array and deletion of an elements in the array

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *ptr;
int size;
int n;

void insert(int pos,int ele)
{
	int i;
	for(i=n;i>=pos;i--)
	{
		*(ptr+i)=*(ptr+i-1);
	}
	*(ptr+i)=ele;
	n++;
	
}

void delete(int pos)
{
	int i;
	for(i=pos-1;i<n-1;i++)
	{
		*(ptr+i)=*(ptr+i+1);
	}
	n--;
}


void print()
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(ptr+i));
	}
	printf("\n");
}





void main()
{
	printf("Enter the size of the array");
	
	
	
	scanf("%d",&size);
	
	
	
	printf("Enter the no of elements in the array");
	
	scanf("%d",&n);
	
	printf("Enter the elements");
	
	//allocating space for the array
	
	ptr=(int *)malloc(size * (sizeof(int)));
	
	int i;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",(ptr+i));
	}
	
	//scanned some of the elements 
	
	insert(2,60);
	
	printf("Printing the array after insertion\n");
	print();
	
	
	insert(3,70);
	printf("Printing the array after insertion\n");
	print();
	
	delete(2);
	printf("Printing the array after deletion\n");
	print();
	
	delete(3);
	printf("Printing the array after deletion\n");
	print();
	
}	

	
	
	
	
	
