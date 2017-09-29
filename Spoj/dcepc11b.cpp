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

LL int getll()
{
	char c=getchar();
	LL int x=0;
	int flag=0;
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

LL power(LL b,LL e, LL mod)
{
	if (e == 0)
		return 1;
	if (e == 1)
		return b;
	LL out = power(b,e/2,mod);
	if (e%2 == 0)
		return (out*out)%mod;
	else
		return (((out*out)%mod)*b)%mod;
}

int main()
{
	int T=get();
	while (T--)
	{
		LL n,p;
		n=getll();
		p=getll();
		if (p<=n)
			printf("0\n");
		else
		{
			LL ans = p-1;
			for (int i=n+1;i<p;i++)
			{
				LL tmp = power(i,p-2,p);
				ans = ((ans*tmp)%p);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}