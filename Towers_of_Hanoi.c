#include<stdio.h>
#include<string.h>

void fun(int n,char s,char a,char d)
{
	if(n==1)
	{
		printf("Move %c to %c\n",s,d);
	}
	else
	{
		fun(n-1,s,d,a);
		printf("Move %c to %c\n",s,d);
		fun(n-1,a,s,d);
	}
}
		


int main()
{
	int n=5;
	fun(n,'s','a','d');
	return 0;
}