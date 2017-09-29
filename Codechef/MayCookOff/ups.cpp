#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[100005],b[100005];

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

bool cmp(const int &a,const int &b)
{
	return ((a)<(b)); 
}

int main()
{
	int t=get();
	while (t--)
	{
		int n=get();
		for (int i=0;i<n;i++)
			a[i]=get();
		std::sort(&a[0],&a[n],cmp);
		int j=0;
		for (int i=0;i<n&&j<n;i+=2,j++)
			b[i]=a[j];
		for (int i=1;i<n&&j<n;i+=2,j++)
			b[i]=a[j];
		for (int i=0;i<n;i++)
			printf("%d ",b[i]);
	}
	return 0;
}