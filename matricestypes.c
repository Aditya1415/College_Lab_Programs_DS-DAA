//different types of matrices
//like lower triangular upper triangular ...tri diagonal matrix 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *ptr;

int size;

void insert(int i,int j,int value)
{
	if(i<j && value>0)
	{
		printf("Error");
	}
	else
	{
	int pos=(i * (i+1))/2 +j;
	
	*(ptr+pos)=value;
	}
}

void print()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i>=j)
			{
				int pos=(i * (i+1))/2 +j;
				printf("%d ",*(ptr+pos));
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
				
		



void main()
{
	size=3;
	
	//allocating the space for the required pointer
	
	//so we will have in lower or upper triangular matric the no of maximum elements is n*(n+1)/2
	
	ptr=(int *)malloc(((size * (size+1))/2) * sizeof(int));
	
	//lower triangular matric means we will have elements below the main disagonal
	//upper menas we will have elements above the main/principal diagonal
	
	insert(0,0,1);
	insert(1,0,4);
	insert(1,1,2);
	insert(2,0,5);
	insert(2,1,6);
	insert(2,2,3);
	
	print();
}
	

