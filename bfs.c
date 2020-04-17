//graphs bfs and dfs

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *circularqueue,*visited;

int start=-1,rear=-1;

int n;
int e;

int matrix[100][100];


void push(int ele)
{
	if((rear+1)%n!=start)
	{
		rear=(rear+1)%n;
		*(circularqueue+rear)=ele;
	}
}

void pop()
{
	if(start!=rear)
	{
		start=(start+1)%n;
	}
}

int front()
{
	if(start==rear)
	{
		return -1;
	}
	else
	{
		int pos=(start+1)%n;
		return(*(circularqueue+(pos)));
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
	
	circularqueue=(int *)malloc(n *sizeof(int));
	visited=(int *)malloc((n) * sizeof(int));
	
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
	printf("The no of components in the graph is %d",count);
}
	
	
