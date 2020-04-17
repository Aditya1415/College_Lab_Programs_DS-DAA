//Addition of two sparse matrix

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sparse
{
	int row;
	int coloumn;
	int value;
}sparse;

sparse *matrix_a,*matrix_b,*matrix_c;


int m,n; //m n indicates the no of elements in the matrix A and B respectively i.e is the no of non zero values in matrix A and B

int size;//size indicates the size * size matrix


void add()
{
	int i=0,j=0;
	int k=0;
	while(i<m && j<n)
	{
		if((((matrix_a +i)->row == (matrix_b+j)->row)) && (((matrix_a +i)->coloumn == (matrix_b +j)->coloumn)))
		{
			(matrix_c +k)->row =(matrix_a + i)->row;
			(matrix_c +k)->coloumn =(matrix_a + i)->coloumn;
			(matrix_c +k)->value =(matrix_a + i)->value + (matrix_b +j)->value;
			i++,k++,j++;
		}
		else if((matrix_a +i)->row < (matrix_b+j)->row)
		{
			(matrix_c +k)->row =(matrix_a + i)->row;
			(matrix_c +k)->coloumn =(matrix_a + i)->coloumn;
			(matrix_c +k)->value =(matrix_a + i)->value;
			i++,k++;
		}
		else if((matrix_a +i)->row > (matrix_b+j)->row)
		{
			(matrix_c +k)->row =(matrix_b + j)->row;
			(matrix_c +k)->coloumn =(matrix_b + j)->coloumn;
			(matrix_c +k)->value =(matrix_b + j)->value;
			k++,j++;
		}
		else
		{
			if((matrix_a+i)->coloumn < (matrix_a +j)->coloumn)
			{
				(matrix_c +k)->row =(matrix_a + i)->row;
				(matrix_c +k)->coloumn =(matrix_a + i)->coloumn;
				(matrix_c +k)->value =(matrix_a + i)->value;
				i++,k++;
			}
			else
			{
				(matrix_c +k)->row =(matrix_b + j)->row;
				(matrix_c +k)->coloumn =(matrix_b + j)->coloumn;
				(matrix_c +k)->value =(matrix_b + j)->value;
				k++,j++;
			}
		}
	}
	while(i<m)
	{
		(matrix_c +k)->row =(matrix_a + i)->row;
		(matrix_c +k)->coloumn =(matrix_a + i)->coloumn;
		(matrix_c +k)->value =(matrix_a + i)->value;
		i++,k++;
	}
	while(j<n)
	{
		(matrix_c +k)->row =(matrix_b + j)->row;
		(matrix_c +k)->coloumn =(matrix_b + j)->coloumn;
		(matrix_c +k)->value =(matrix_b + j)->value;
		k++,j++;
	}
}	
				
				

int check(sparse *ptr,int nz,int x,int y)
{
	int i;
	for(i=0;i<nz;i++)
	{
		if((ptr+i)->row==x && (ptr+i)->coloumn==y)
		{
			return((ptr+i)->value);
		}
	}
	return 0;
}



void print(sparse *ptr,int nz) //nz indicates no of non zero values
{
		int i,j;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				printf("%d ",check(ptr,nz,i,j));
			}
			printf("\n");
		}
}







void main()
{
	printf("Enter the size of the two matrices\n");
	
	scanf("%d",&size);
	
	printf("Enter the non zero number of values in sparse matrix in A\n");
	
	scanf("%d",&m);
	
	//Allocating the space for matrix A i.e in the sparse matrix we store the 2D matrix into 1D matrix i.e the speciality
	
	matrix_a=(sparse *)malloc(m * sizeof(sparse));
	
	printf("Enter the non zero values in the sparse matrix B\n");
	
	scanf("%d",&n);
	
	matrix_b=(sparse *)malloc(n * sizeof(sparse));
	
	//so when we add the two sparse matrices the no of elements mostly will be m+n
	
	matrix_c=(sparse *)malloc((m+n) * (sizeof(sparse)));
	
	//so now enter the respective row value coloumn value and the value/cost of it
	
	int i,j;
	
	printf("Enter the data of the matrix A");
	
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d ",&(matrix_a+i)->row,&(matrix_a+i)->coloumn,&(matrix_a +i)->value);
	}
	
	printf("Enter the data of the matrix B");
	
	for(j=0;j<n;j++)
	{
		scanf("%d%d%d ",&(matrix_b+j)->row,&(matrix_b+j)->coloumn,&(matrix_b +j)->value);
	}
	
	
	printf("printing the sparse matrix A \n");
	print(matrix_a,m);
	
	printf("printing the sparse matrix B \n");
	print(matrix_b,n);
	
	//calling the add function to add the two sparse matrices
	
	add();
	
	printf("printing the matrix c\n");
	print(matrix_c,m+n);
	
	
}
		
