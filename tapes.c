#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;//n indicates no of tapes


int comp(const void *a,const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	
	return x>y;
}


int main()
{
	printf("Enter the no of tapes");
	scanf("%d",&n);
	
	int *arr;
	arr=(int *)malloc(n * sizeof(int));
	
	printf("Enter the sizes of tapes");
	
	int i;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	//sorting the tapes
	qsort(arr,n,sizeof(int),comp);
	
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	//after sorting..
	
	int j;
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			sum=sum+arr[j];
		}
		printf("%d\n",sum);
	}
	printf(" \n Total optimal tape %d",sum);
			
			
	
	
	
	
	
	return 0;
}