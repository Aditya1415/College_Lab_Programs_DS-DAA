//brackets //paranthesis checking

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
	char data;
}stack;

int top=-1;

char input[20];

stack *ptr;

void push(char ch)
{
	top++;
	(ptr+top)->data=ch;
}

char pop()
{
	char temp=(ptr+top)->data;
	top--;
	return temp;
}

void go()
{
	int i;
	for(i=0;input[i]!='\0';i++)
	{
		if((input[i]=='(' || input[i]=='{' || input[i]=='['))
		{
			push(input[i]);
		}
		else if(input[i]==')')
		{
			if(pop()!='(')
			{
				printf("Not matched");
				break;
			}
			
		}
		else if(input[i]=='}')
		{
			if(pop()!='{')
			{
				printf("Not matched");
				break;
			}
			
		}
		else if(input[i]==']')
		{
			if(pop()!='[')
			{
				printf("Not matched");
				break;
			}
			
		}
	}
	if(i==strlen(input))
	{
		printf("Matched");
	}
	else
	{
		printf("Not matched");
	}
}
		
		


void main()
{
	printf("Enter the string");
	scanf("%s",input);
	
	ptr=(stack *)malloc(strlen(input) * (sizeof(stack)));
	
	go();
}