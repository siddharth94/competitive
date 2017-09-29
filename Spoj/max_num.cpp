#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long 

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

char n[100009];

int main()
{
	int T = get();
	while (T--)
	{
		int k;
		c=getchar();
		while (c>='0' && c<='9')
		{
			n[i++] = c;
			c=getchar();
		}
		k = get();
		if (k==n)
			printf("\n");
		else
		{

		}
	}
	return 0;
}