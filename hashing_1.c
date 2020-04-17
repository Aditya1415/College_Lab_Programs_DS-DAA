//linear open addressing

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct item
{
	int key;
	int value;
}item;

struct hashtable
{
	int flag;
	struct item *data;
}hashtable;

struct hashtable *array;

int size=0;

int max=10;

void array1()
{
	int i;
	for(i=0;i<max;i++)
	{
		array[i].flag=0;
		array[i].data=NULL;
	}
}

void insert(int value1)
{
	int index =value1 %max;
	int i=index;
	struct item *item1=(struct item *)malloc(sizeof(item));
	
	item[key]=index;
	item[value]=value1;
	
	while(array[index].flag ==1)
	{
		if(array[index].data ->key ==index)
		{
			array[index].data->value=value1;
		}
		index=(index+1)%max;
		
		if(i==index)
		{
			printf("hash Table is full");
		}
		array[index].flag=1;
		array[i].data=value;
		size++;
	}
}

void display()
{
	int i;
	for(i=0;i<max;i++)
	{
		struct item *c=(struct item *) array[i].data;
		
		if(c==NULL)
		{
			printf("Has no elements");
		}
		else
		{
			printf("%d %d",c->key,c->value);
		}
	}
}

void main()
{
	insert(25);
	insert(30);
	insert(40);
	insert(255);
]






void main()
{
	