#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct edge
{
	int source;
	int destination;
	int weight;
}edge;


typedef struct subset
{
	//this structure is used to update each vertex as parent and having a rank of it
	
	int parent;
	int rank;
}subset;
	



	
edge *edgeptr;

subset *parentptr;

edge *edgeresultptr;

	
int ne;//no of edges

int nv;//no of vertices

int comp(const void *a,const void *b)
{
	edge a1=*(edge *) a;
	edge a2=*(edge *) b;
	
	return a1.weight > a2.weight;
}


int find(int i)
{
	while((parentptr+i)->parent!=i)
	{
		i=(parentptr+i)->parent;
	}
	return (parentptr+i)->parent;
}
		
void union1(int x,int y)
{
	x=find(x);
	y=find(y);
	if((parentptr+x)->rank < (parentptr +y)->rank)
	{
		(parentptr+y)->parent=x;
	}
	else if((parentptr+x)->rank > (parentptr +y)->rank)
	{
		(parentptr+x)->parent=y;
	}
	else
	{
		(parentptr+x)->parent=y;
		(parentptr+y)->rank++;
	}
}
	




int main()
{
	
	printf("Enter the no of vertices");
	scanf("%d",&nv);
	
	printf("Enter the no of edges");
	scanf("%d",&ne);
	
	//intializing the edge ptr
	
	edgeptr=(edge *)malloc(ne * sizeof(edge));
	
	printf("Enter the %d vertices src destination and weight respectively\n",ne);
	
	int i;
	
	for(i=0;i<ne;i++)
	{
		scanf("%d %d %d",&(edgeptr+i)->source,&(edgeptr+i)->destination,&(edgeptr+i)->weight);
	}
	
	//so now sort the weights
	
	qsort(edgeptr,ne,sizeof(edge),comp);
	
	//printing the edges in the sorted order
	
	for(i=0;i<ne;i++)
	{
		printf("%d %d %d\n",(edgeptr+i)->source,(edgeptr+i)->destination,(edgeptr+i)->weight);
	}
	
	
	//now after sorting the edges we need to take the edges one by one from the sorted list and start doing the kruskal algorithm
	//take the edge and connect the both i.e do the union of the both go on doing the union and cycle should not form 
	//checking cycle is by seeing the parent and destination of the src and the destination
	
	//first intially all the vertices rank will be 0 since we take into consideration that no edge is connected first
	
	//first we need to allocate the space for parent ptr allocate the space as of that of no of vertices
	
	parentptr=(subset *)malloc(nv * sizeof(subset));
	
	for(i=0;i<nv;i++)
	{
		
		//we know that every node initally has no connection so taking into consideration its parent initially will be itself
		(parentptr+i)->parent=i;
		(parentptr+i)->rank=0;
	}
	
	//now we need to see the resultant edge array need to initialize the edgeresultant array
	
	edgeresultptr=(edge *)malloc((nv) * sizeof(edge));
	
	//so now we need to go into the picture of kruskal
	
	int a=0;
	int b=0;
	
	while(a < nv-1 && b<ne)
	{
		edge tempedge=*(edgeptr+b);
		
		int s=find(tempedge.source);
		int d=find(tempedge.destination);
		
		if(s!=d) //no cycle formation can be taken place
		{
			
			//i.e an edge is taken
			
			union1(tempedge.source,tempedge.destination);
			
			//adding the edge into the resulatnt
			
			*(edgeresultptr+a)=tempedge;
			
			a++;
		}
		b++;
	}
	
	//in the resultant edges we have the required edges which can be mapped
	
	
	printf("\nSource Destination Weight\n");
	for(i=0;i<a;i++)
	{
		printf("%d\t%d\t%d\n",(edgeresultptr+i)->source,(edgeresultptr+i)->destination,(edgeresultptr+i)->weight);
	}
	
	
	return 0;
}
	
	
	
	