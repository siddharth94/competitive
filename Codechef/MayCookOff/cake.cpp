#include<cstdio>
#include<iostream>
using namespace std;

int get()
{
	char c=getchar();
	int x=0,flag=0;
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-')
	{
		flag=1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return flag?(-x):x;
}

int main()
{
	int t=get();
	while (t--)
	{
		int n=get();
		if (360%n==0)
			printf("y ");
		else printf("n ");
		if (n<=360)
			printf("y ");
		else printf("n ");
		if (n<27)
			printf("y\n");
		else printf("n\n");
	}
}