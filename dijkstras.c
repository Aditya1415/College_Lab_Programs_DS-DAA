#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define infinity 9999

int nv;

int ne;

int matrix[1000][1000];

int startingnode;


int cost[100][100]; //cost of between one vertex and other vertexes


int distance[10]; //distance to each vertex from source


int visited[10];



void dijkastras()
{
	
	int i,j;
	
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
			if(matrix[i][j]==0)
			{
				cost[i][j]=infinity;
			}
			else
			{
				cost[i][j]=matrix[i][j];
			}
		}
	}
	//cost matrix is done
	
	
	for(i=0;i<nv;i++)
	{
		distance[i]=cost[startingnode][i];
		visited[i]=0;
	}
	
	visited[startingnode]=1;
	distance[startingnode]=0;
	
	int count=1;
	
	while(count<nv -1)
	{
		//count < nv-1 is that number of relaxations
		//find the shortest distance from the source i.e find the shortest vertex from source
		
		//let the first minimal distance be the infinity defined by us
		
		int mindistance=infinity;
		int nextnode=i;
		for(i=0;i<nv;i++)
		{
			if(distance[i] < mindistance && !visited[i])
			{
				nextnode=i;
				mindistance=distance[i];
			}
		}
		
		//we found the index of the node which is very nearer to the source
		//so make its visted as 1
		
		visited[nextnode]=1;
		
		//so traverse with this nextnode to the other nodes similarly with those to the others
		
		for(i=0;i<nv;i++)
		{
			if(!visited[i])
			{
				if(cost[nextnode][i]+mindistance < distance[i])
				{
					distance[i]=cost[nextnode][i]+mindistance;
				}
			}
		}
		count++;
	}
	printf("\n");
	for(i=0;i<nv;i++)
	{
		printf("Node %d Distance %d\n",i,distance[i]);
	}
	
	
	
}
		
			

int main()
{
	printf("Enter the no of vertices");
	scanf("%d",&nv);
	
	printf("Enter the no of edges");
	scanf("%d",&ne);
	
	memset(matrix,0,sizeof(matrix));
	
	printf("Enter the %d edges and their costs",ne);
	
	int i,j;
	
	int a,b,c;
	for(i=0;i<ne;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		
		//assuming to be undirected graph
		
		matrix[a][b]=c;
		matrix[b][a]=c;
	}
	
	printf("\nEnter the starting node");
	scanf("%d",&startingnode);
	
	
	dijkastras();
		
	return 0;
}
	
	
	