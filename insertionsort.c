//insertion sort

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	char name[20];
	int marks;
}student;


void display(student *ptr,int n)
{
	int i;
	printf("\n");
	printf("Name:------------|Marks:------------\n");
	for(i=0;i<n;i++)
	{
		printf("%s           |%d                \n",(ptr+i)->name,(ptr+i)->marks);
	}
	printf("\n");
}


void insertionsort(student *ptr,int n)
{
	int i,j;
	
	student key;
	for(i=1;i<n;i++)
	{
		j=i-1;
		key=*(ptr+i);
		
		while(j>=0 && (ptr+j)->marks > key.marks)
		{
			
		
			*(ptr+j+1)=*(ptr+j);
			j=j-1;
		}
		*(ptr+j+1)=key;
	}
}
	



void main()
{
	
	student *ptr;//i.e the array of the students

	int n;
	
	printf("Enter the no of student details that u want to enter\n");
	scanf("%d",&n);
	
	//allocating the space for the student pointer
	
	ptr=(student *)malloc(n * (sizeof(student)));
	
	printf("Enter the name and the marks of the student\n");
	
	int i;
	
	for(i=0;i<n;i++)
	{
		scanf("%s%d ",(ptr+i)->name,&(ptr+i)->marks);
	}
	printf("Before sorting as per the marks");
	display(ptr,n);
	
	printf("After sorting as per the marks");
	insertionsort(ptr,n);
	display(ptr,n);
}