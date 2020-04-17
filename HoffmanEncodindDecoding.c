#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int freq;
	char chr;
	struct node *left;
	struct node *right;
}node;

typedef struct strdata
{
	char ch;
	int frequency;
}strdata;


typedef struct stringstorage
{
	char ch;
	char *chararray;
}stringstorage;




strdata *strptr;
int count=0;

int strcount=0;

stringstorage *result; 

char message[100];

char dmessage[100];

node **minheap;

int n;

int array[100];

void swap(int x,int y)
{
	node *temp=minheap[x];
	minheap[x]=minheap[y];
	minheap[y]=temp;
}


void heapify(int root)
{

	int l=2*root+1;
	int r=2*root+2;
	int m=root;
	
	
	if(l<n && (minheap[l])->freq < (minheap[m])->freq )
	{
		m=l;
	}
	if(r<n && (minheap[r])->freq < (minheap[m])->freq )
	{
		m=r;
	}
	if(m!=root)
	{
		swap(m,root);
		heapify(m);
	}
}
	
	


void buildheap()
{
	int i;
	for(i=n/2 -1;i>=0;i--)
	{
		
		heapify(i);
		
	}
}


void printheap()
{
	int i;
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		
		printf("%c %d\n",(minheap[i])->chr,(minheap[i])->freq);
	}
}

void delete(int pos)
{
	swap(pos,n-1);
	n--;
	
	buildheap();
}

void insert(node *temp)
{
	minheap[n]=temp;
	n++;
	buildheap();
}
	
	
void traversal(node *temp)
{
	if(temp)
	{
		traversal(temp->left);
		printf("\nThe character is %c and frequency is %d",temp->chr,temp->freq);
		traversal(temp->right);
	}
	
}





void calculate()
{
	int i;
	
	//we have already initialized the stringptr
	//assuming all the characters to be lower letters
	for(i=0;i<26;i++)
	{
		(strptr+i)->frequency=0;
		(strptr+i)->ch=97+i;
	}
	
	
	for(i=0;message[i]!='\0';i++)
	{
		//message[i] has a character
		
		int pos=message[i]-'a';
		(strptr+pos)->frequency=(strptr+pos)->frequency +1;
	}
	printf("\n");
	for(i=0;i<26;i++)
	{
		if((strptr+i)->frequency > 0)
		{
			count++;
			printf("%c %d\n",(strptr+i)->ch,(strptr+i)->frequency);
		}
	}
	printf("The no of characters is %d",count);
	
}	

void hoffmanfun()
{
	int i=0,x=n;
	
	while(i<x-1)
	{
		node *firstnode=minheap[0];
		delete(0);
		
		node *secondnode=minheap[0];
		delete(0);
		
		node *thirdnode=(node *)malloc(sizeof(node));
		
		thirdnode->chr='?';
		thirdnode->freq=firstnode->freq + secondnode->freq;
		thirdnode->left=firstnode;
		thirdnode->right=secondnode;
		
		insert(thirdnode);
		
		printheap();
		i++;
		
	}
	
}		
void storestring(char ch1,int top)
{
	(result+strcount)->chararray=(char *)malloc((top+1) * sizeof(char));
	(result+strcount)->ch=ch1;
	
	int i;
	for(i=0;i<top;i++)
	{
		if(array[i]==0)
		{
			(result+strcount)->chararray[i]='0';
		}
		if(array[i]==1)
		{
			(result+strcount)->chararray[i]='1';
		}
	}
	(result+strcount)->chararray[i]='\0';
	
	strcount++;
}

void printstringarray()
{
		int i;
		for(i=0;i<count;i++)
		{
			printf("\n The character is %c and the string is %s\n",(result+i)->ch,(result+i)->chararray);
		}
}
	
	


void gototree(node *p,int top)
{
	if(p->left)
	{
		array[top]=0;
		gototree(p->left,top+1);
	}
	if(p->right)
	{
		array[top]=1;
		gototree(p->right,top+1);
	}
	if(!p->left && !p->right)
	{
		//this will be our character node
		
		//printf("The character is %c\n",p->chr);
		storestring(p->chr,top);
		
	}
}
	
	
		
		


int main()
{
	strptr=(strdata *)malloc(26 * sizeof(strdata));
	
	printf("Enter the message\n");
	gets(message);
	printf("%s",message);
	
	calculate();//this function is used for having the information regarding the cgaracters of the message
	
	n=count;
	
	//now allocate the space for minheap
	
	minheap=(node **)malloc(count * sizeof(node*));
	
	result=(stringstorage *)malloc(count * sizeof(stringstorage));
	
	int x=0;
	int i;
	for(i=0;i<count;i++)
	{
		minheap[i]=NULL;
	}
	printf("\n");
	for(i=0;i<26;i++)
	{
		if((strptr+i)->frequency >0)
		{
			node *temp=(node *)malloc(sizeof(node));
			
			temp->chr=(strptr+i)->ch;
			
			temp->freq=(strptr+i)->frequency;
			
			temp->left=NULL;
			temp->right=NULL;
				
			minheap[x]=temp;
			
			printf("%c %d from minheap\n",minheap[x]->chr,minheap[x]->freq);
			
			x++;
		}
	}
	
	printheap();
	
	
	//buildheap for building a minheap
	buildheap();
	
	printheap();
	
	//hoffmanfun();
	
	hoffmanfun();
	
	node *temp=minheap[0];
	
	traversal(temp);
	printf("\n");
	
	//now we need to encode and decode
	
	gototree(minheap[0],0);
	
	
	printstringarray();
	
	
	return 0;
}
	
	
	
