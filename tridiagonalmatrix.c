//tridiagonal matric

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *ptr;

int size=5;

void insert(int i,int j,int value)
{
	int pos=2*i+j;
	if(abs(i-j) >=2 && value!=0)
	{
		printf("Error-----------------------Exiting");
		exit(0);
	}
	else
	{
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
			int pos=2*i+j;
			if(abs(i-j) >=2)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ",*(ptr+pos));
			}
		}
		printf("\n");
	}
}
			




void main()
{
	
	//allocating the space for the pointer
	
	//the space allocated for the tridiagonal matrix is 3*(n) -2

	//I have fixed my size as 5 in this program 
	
	ptr=(int *)malloc((3*size -2) * (sizeof(int)));
	
	insert(0,0,1);
	insert(0,1,2);
	insert(1,0,3);
	insert(1,1,4);
	insert(1,2,5);
	insert(2,1,6);
	insert(2,2,7);
	insert(2,3,8);
	insert(3,2,9);
	insert(3,3,10);
	insert(3,4,11);
	insert(4,3,12);
	insert(4,4,13);
	
	print();
}


