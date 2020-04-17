//heapsort

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void heapify(student *ptr,int root,int end)
{
	int left=2*root+1;
	int right=2*root+2;
	int maximum=root;
	
	if( left <end && (ptr+left)->marks > (ptr+maximum)->marks)
	{
		maximum=left;
	}
	if(right <end && (ptr+right)->marks > (ptr+maximum)->marks)
	{
		maximum=right;
	}
	if(maximum!=root)
	{
		//swap maximum and root
		student temp=*(ptr+maximum);
		*(ptr+maximum)=*(ptr+root);
		*(ptr+root)=temp;
		
		heapify(ptr,maximum,end);
	}

	
}	
	


void heapsort(student *ptr,int leftindex,int endindex)
{
	//first we need to heapify the heap
	
	int i;
	int x=endindex;
	for(i=(x/2)-1;i>=0;i--)
	{
		heapify(ptr,i,endindex);
	}
	
	//after heapifying we need to heap sort it
	int j;
	
	for(j=endindex -1;j>=0;j--)
	{
		//swapping the 0 and j th term
		student temp=*(ptr+j);
		*(ptr+j)=*(ptr+0);
		*(ptr+0)=temp;
		
		//now we need to heapify the structure again
		
		heapify(ptr,0,j);
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
	heapsort(ptr,0,n);
	display(ptr,n);
}
	
	