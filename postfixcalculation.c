//postfix value calculation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct stack
{
	int data;
}stack;

stack *ptr;
int top=-1;
int a,b,c;
char input[20];

void push(int ele)
{
	top++;
	(ptr+top)->data=ele;
}

int pop()
{
	int x=(ptr+top)->data;
	top--;
	return x;
}



void go()
{
	int i;
	
	for(i=0;input[i]!='\0';i++)
	{
		
		if(isalnum(input[i]))
		{
			push(input[i] - '0');
		}
		else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/')
		{
			
			char temp=input[i];
			a=pop();
			b=pop();
			
			switch(temp)
			{
				
				
				
				case '+': c=a+b;
							push(c);
							break;
				case '-':  c=-a+b;
							push(c);
							break;
				case '*': c=a*b;
							push(c);
							break;
				case '/': c=b/a;
						 push(c);
							break;
			
			}
		}
	}
	printf("\n%d",c);
}



void main()
{
	printf("Enter the string");
	
	scanf("%s",input);
	
	ptr=(stack *)malloc( strlen(input) *sizeof(stack));
	
	go();
}
