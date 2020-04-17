#include<stdio.h>
#include<stdlib.h>

void spiral(int m,int n,int a[m][n])
{
	int i,j;
	int k=0,l=0;//k-starting of row,l-starting of column
	while(k<m && i<n)
	{
		for(i=l;i<n;i++)
		{
			printf("%d",a[k][i]);
		}
		k++;
		for(i=k;i<m;i++)
		{
			printf("%d",a[i][n-1]);
		}
		n--;
		if(k<m)
		{
			for(i=n-1;i>=l;i--)
			{
				printf("%d",a[m-1][i]);
			}
			m--;
		}
		if(l<n)
		{
			for(i=m-1;i>=k;i--)
			{
				printf("%d",a[i][l]);
			}
			l++;
		}
	}
}

void main()
{
	int m,n;//m-no.of rows,n-no.of columns
	printf("enter no.of rows");
	scanf("%d",&m);
	printf("enter no.of cols");
	scanf("%d",&n);
	int mat[m][n];
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("\n\n matrix :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	spiral(m,n,mat);
}