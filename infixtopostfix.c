//infix to postfix conversion


//in this program we have to push the characters into the other string and opearators to the stack and operators popping based on the precedence

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

typedef struct stack
{
	char ch;
}stack;

stack *ptr;

int top=-1;

char input[20]; //input string
char output[20]; //output string

void push(char ch1)
{
	top++;
	(ptr+top)->ch=ch1;
}

int precedence(char ele)
{
	if(ele=='+' || ele=='-')
	{
		return 2;
	}
	else if(ele =='*' || ele=='/')
	{
		return 3;
	}
	else if(ele=='(')
	{
		return 1;
	}
	else if(ele=='#')
	{
		return 0;
	}
}


char pop()
{
	char temp=(ptr+top)->ch;
	top--;
	return temp;
}

void check()
{
	//in this function we will go through the two strings
	
	push('#');
	int i;
	int j=0;
	char temp;
	
	for(i=0;input[i]!='\0';i++)
	{
		if(isalpha(input[i]))
		{
			output[j]=input[i];
			j++;
		}
		else if(input[i]=='(')
		{
			push('(');
		}
		else if(input[i]==')')
		{
			while((temp=pop())!='(')
			{
					output[j]=temp;
					j++;
			}
		}
		else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/')
		{
			temp=pop();
			while(precedence(temp) > precedence(input[i]))
			{
				output[j]=temp;
				j++;
				temp=pop();
			}
			push(temp);
			push(input[i]);
		}
	}
	while(top!=0)
	{
		output[j]=pop();
		j++;
	}
}
			
void display()
{
	int i;
	for(i=0;output[i]!='\0';i++)
	{
		printf("%c",output[i]);
	}
}
	




void main()
{
	printf("Enter the input String");
	scanf("%s",input);
	
	
	//need to allocate the space for the stack pointer
	
	ptr=(stack *)malloc(strlen(input) +2 *(sizeof(stack)));
	
	check();
	display();
}
	