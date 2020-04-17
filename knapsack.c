//knap sack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct knapsack
{
	int profit;
	int weight;
	float pw;
}knapsack;

knapsack *ptr;


int n;

int m;

int maxquantity;

void sortaspw()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((ptr+i)->pw > (ptr+j)->pw)
			{
				//swap
				
				knapsack temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
			}
		}
	}
}

void display()
{
	int i;
	for(i=0;i<n;i++)
	{	
		printf("%d %d %f\n",(ptr+i)->profit,(ptr+i)->weight,(ptr+i)->pw);
	}
}
	

void funknapsack()
{
	int sum=0;
	
	int i=0;
	
	float *x=(float *)malloc(n * sizeof(float));
	
	int rem=m;
	
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		if((ptr+i)->weight > rem)
		{
			break;
		}
		x[i]=1;
		rem=rem- (ptr+i)->weight;
	}
	if(i<=n)
	{
		x[i]=(float)rem/(ptr+i)->weight ;
	}
	
	
	for(i=0;i<n;i++)
	{
		if(x[i]!=0)
		{
			printf("%f\n", (x[i] * (ptr+i)->profit));
		}
	}
		
			
	
	
}
	
		

		
	



int main()
{
	printf("Enter the no of objects");
	scanf("%d",&n);
	
	printf("\n Enter the maximum weight of the knapsack");
	scanf("%d",&m);
	
	printf("\n Enter the profit and weight of each object");
	
	ptr=(knapsack *)malloc(n *sizeof(knapsack));
	
	int i;
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&(ptr+i)->profit,&(ptr+i)->weight);
		(ptr+i)->pw=(float)((ptr+i)->profit / (ptr+i)->weight);
	}
	
	sortaspw();

	display();
	
	funknapsack();
	
	return 0;
	
}