//dfs
//graphs bfs and dfs

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *stack,*visited;

int top=-1;

int n;
int e;

int matrix[100][100];


void push(int ele)
{
	top++;
	*(stack +top)=ele;
}

void pop()
{
	top--;
}

int front()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
	return(*(stack+(top)));
	}
}



void bfs(int i)
{

	push(i);

	int j;
	
	while((i=front())!=-1)
	{
		pop();
		for(j=1;j<n+1;j++)
		{
			if(visited[j]==0 && matrix[i][j]==1)
			{
				visited[j]=1;
				push(j);
			}
		}
	}
}

	

void main()
{
	printf("Enter the no of vertices in the graph");
	scanf("%d",&n);
	
	printf("Enter the no of edges in the graph");
	scanf("%d",&e);
	
	memset(matrix,0,sizeof(matrix));
	
	stack=(int *)malloc(n *sizeof(int));
	visited=(int *)malloc((n+1) * sizeof(int));
	
	int i;
	
	printf("Enter the connection between the nodes");
	int x,y;
	
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&x,&y);
		matrix[x][y]=1;
		matrix[y][x]=1;
	}
	int count=0;
	
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			bfs(i);
			count++;
		}
	}
	printf("%d",count);
}
	
	
