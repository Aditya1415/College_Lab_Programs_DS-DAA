#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void quicksort(int *arr,int left,int right)
{
	int pivot,i,j;
	if(left < right)
	{
		pivot=left;
		i=left;
		j=right;
		while(i<j)
		{
			while(arr[i] < arr[pivot] && i<=right)
			{
				i++;
			}
			while(arr[j] > arr[pivot] && j>=left)
			{
				j--;
			}
			if(i<j)
			{
				//swap arr[i] and arr[j]
				
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			//	display(arr,5);
			}
		}
		int temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
		//display(arr,5);
		quicksort(arr,left,j-1);
		quicksort(arr,j+1,right);
	}
}









int main()
{
	int *arr;
	int n;
	
	printf("Enter the no of elements of the array");
	
	scanf("%d",&n);
	
	printf("Enter the elements of the array");
	
	int i=0;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",(arr+i));
	}

	printf("Elements before sorting");
	display(arr,n);
	
	quicksort(arr,0,n-1);
	
	printf("Elements after sorting");
	display(arr,n);
}
	