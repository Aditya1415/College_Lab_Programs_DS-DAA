
#include<stdio.h>
#include<stdlib.h>

typedef struct sack
{
	int weight;
	int profit;
}sack;


sack *ptr;

int comp(const void *a,const void *b)
{
	sack a1=*(sack *)a;
	sack a2=*(sack *)b;
	
	return a1.weight > a2.weight;
}

int max(int a,int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}




int main()
{
	int nobjects;
	printf("Enter the no of objects\n");
	scanf("%d",&nobjects);
	
	
	printf("Enter the weights and profits of the %d knao\n",nobjects);
	
	int i;
	
	ptr=(sack *)malloc(nobjects * sizeof(sack));
	
	for(i=0;i<nobjects;i++)
	{
		scanf("%d %d",&(ptr+i)->weight,&(ptr+i)->profit);
	}
	
	//need to sort as per the weights
	
	qsort(ptr,nobjects,sizeof(sack),comp);
	
	
	
	
	//sorted as per the weights;
	
	//knap sack dp;
	
	int maxcapacity;
	printf("Enter the max capacity of the knap sack\n");
	
	scanf("%d",&maxcapacity);
	
	
	
	
	
	//intialisation of a matrix;
	
	
	int matrix[nobjects+1][maxcapacity+1];
	
	int j;
	
	
	
	
	printf("Printing the Matrix\n\n");
	
	for(i=0;i<=nobjects;i++)
	{
		for(j=0;j<=maxcapacity;j++)
		{
			if(i==0||j==0)
			{
				matrix[i][j]=0;
				printf("%d ",matrix[i][j]);
			}
			else if ((ptr+i-1)->weight <= j)
			{
				matrix[i][j] = max((ptr+i-1)->profit + matrix[i-1][j-(ptr+i-1)->weight], matrix[i-1][j]); 
				printf("%d ",matrix[i][j]);
			}
			else
			{
				matrix[i][j] = matrix[i-1][j];
				printf("%d ",matrix[i][j]);				
			}
			
			
		}
		
		printf("\n");
	}
			
	printf("The maximum profit is %d\n",matrix[nobjects][maxcapacity]);	

		
	//need to find the vector;
	
		int maxprofit = matrix[nobjects][maxcapacity];
		int vectorarray[nobjects];

		int w = maxcapacity;
		int k=0;
		
		
		for(i=nobjects;i>0 && maxprofit > 0;i--)
		{
			if(maxprofit == matrix[i-1][w])
			{
				vectorarray[k]=1;
			}
			else
			{
				vectorarray[k]=0;
				maxprofit=maxprofit-(ptr+i-1)->profit;
				w=w-(ptr+i-1)->weight;
			}
			k++;
		}
		printf("Choosen vector is \n");
		
		
		
		for(i=0;i<nobjects;i++)
		{
			printf("%d ",vectorarray[i]);
		}
		
	
			
	return 0;
}
	
		
		
		