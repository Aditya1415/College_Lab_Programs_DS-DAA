//job scheduling

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct job
{
	int timelimit;
	int profit;
}job;



job *jobptr;

job *joballoted;

int n;//n indicates no of jobs


int comp(const void *a,const void *b)
{
	job x=*(job *)a;
	job y=*(job *)b;
	
	return x.profit < y.profit;
}


void printjobs()
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",(jobptr+i)->timelimit,(jobptr+i)->profit);
	}
}

int main()
{
	printf("Enter the no of jobs in the process");
	scanf("%d",&n);
	
	jobptr=(job *)malloc(n * sizeof(job));
	
	int i;
	
	printf("Enter the respective job's and their limitsi.e their deadlines\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&(jobptr+i)->timelimit,&(jobptr+i)->profit);
	}
	
	//need to sort the jobs based on the profits
	
	qsort(jobptr,n,sizeof(job),comp);
		
	printjobs();
	
	//now after sorting the jobs we need to find the max no of days in the job so that we can create a array of that size
	
	int max=(jobptr+0)->timelimit;
	
	for(i=1;i<n;i++)
	{
		if(max < (jobptr+i)->timelimit)
		{
			max=(jobptr+i)->timelimit;
		}
	}
	
	//we found the max no of working days so need to create a vector/array of thet size
	
	
	joballoted=(job *)malloc(max * sizeof(job));
	
	int *bitvector=(int *)calloc(0,max+1 * sizeof(int));
	
	max=max+1;
	int count=0;
	
	for(i=0;i<n && count<max;i++)
	{
		//take the job from the job ptr array as it is sorted the first one will have the highest profit allot it into the job allot array
		
		//take the ith  process and allocate to the joballocated and check whether if its allocated or not
		
		job temp=*(jobptr+i);
		
		if(bitvector[temp.timelimit]==0)
		{
			*(joballoted+temp.timelimit)=temp;
			bitvector[temp.timelimit]==1;
			count++;
		}
		else if(bitvector[temp.timelimit]==1)
		{
			int j;
			for(j=temp.timelimit-1;j>=0;j--)
			{
				if(bitvector[j]==0)
				{
					*(joballoted+j)=temp;
					bitvector[j]==1;
					count++;
					break;
				}
			}
		}
		
	}
		
	
	printf("\n");
	for(i=0;i<max;i++)
	{
		printf("%d %d\n",(joballoted+i)->timelimit,(joballoted+i)->profit);
	}
	
	
	return 0;
}