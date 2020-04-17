//we will start sorting techniques

//start with the merge sorting

//sort according to the marks of the students

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

void merge(student *ptr,int left,int middle,int right)
{
	int i=left;
	int j=middle+1;
	
	student *temp=(student *)malloc((right-left +1) * (sizeof(student)));
	
	int k=0;
	
	//merging concept;
	
	while(i<=middle && j<=right)
	{
		if((ptr+i)->marks < (ptr+j)->marks)
		{
			*(temp+k)=*(ptr+i);
			i++,k++;
		}
		else if((ptr+i)->marks > (ptr+j)->marks)
		{
			*(temp+k)=*(ptr+j);
			j++,k++;
		}
		else
		{
			*(temp+k)=*(ptr+i);
			i++,k++;
			*(temp+k)=*(ptr+j);
			j++,k++;
		}
	}
	while(i<=middle)
	{
		*(temp+k)=*(ptr+i);
			i++,k++;
	}
	while(j<=right)
	{
		*(temp+k)=*(ptr+j);
		j++,k++;
	}
	for(i=left,j=0;i<=right;i++,j++)
	{
		*(ptr+i)=*(temp+j);
	}
	
		
}
		
		

void mergesort(student *ptr,int left,int right)
{
	if(left<right)
	{
		
		int middle=(left+right)/2;
		mergesort(ptr,left,middle);
		mergesort(ptr,middle+1,right);
		merge(ptr,left,middle,right);
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
		scanf("%s %d ",(ptr+i)->name,&(ptr+i)->marks);
	}
	printf("Before sorting as per the marks");
	display(ptr,n);
	
	printf("After sorting as per the marks");
	mergesort(ptr,0,n-1);
	display(ptr,n);
}
	
	