//priority queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct pq
{
	int frequency;
	char character[1];
}pq;


int n;


pq *ptr;

void print()
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%s     %d",(ptr+i)->character,(ptr+i)->frequency);
		printf("\n");
	}
}

void swap(int a,int b)
{
	pq temp=*(ptr+a);
	*(ptr+a)=*(ptr+b);
	*(ptr+b)=temp;
}

void heapify(int root)
{
	int left=2*root+1;
	int right=2*root+2;
	int maximum=root;
	
	if((left <n) && ((ptr+left)->frequency < (ptr+maximum)->frequency))
	{
		maximum=left;
	}
	if((right <n) && ((ptr+right)->frequency < (ptr+maximum)->frequency))
	{
		maximum=right;
	}
	if(maximum!=root)
	{
		swap(maximum,root);
		heapify(maximum);
	}
}
	
	

void buildheap()
{
	//building minheap
	int i;
	for(i=n/2;i>=0;i--)
	{
		heapify(i);
	}
}

void insert(char ch,int freq)
{
	
	char str[2];
	str[0]=ch;
	str[1]='\0';
	strcpy((ptr+n)->character,str);
	(ptr+n)->frequency=freq;
	
	n++;
	
	buildheap();
}

void delete(int pos)
{
	
	//swap the positioned element and the last element and delete the last element then build heap again
	
	swap(pos,n-1);
	
	n--;
	
	buildheap();
}
	
	
	
	
	


int main()
{
	printf("Enter the no of characters thet u have in the string");
	scanf("%d",&n);
	
	ptr=(pq *)malloc(2*n *sizeof(pq));
	
	int i;
	
	printf("Enter the %d characters and their respective frequencies",n);
	
	for(i=0;i<n;i++)
	{
		scanf("%s%d",(ptr+i)->character,&(ptr+i)->frequency);
	}
	
	print();
	
	buildheap();
		
	print();
	
	insert('x',13);
	
	print();
	
	insert('y',24);
	
	print();
	
	insert('z',11);
	
	print();
	
	
	delete(3);
	
	print();
	
	delete(4);
	
	print();
	
	
	return 0;
}