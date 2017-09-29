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

int main()
{
	int T=get();
	F(z,T)
	{
		int n,k,t;
		LL b;
		n=get();
		k=get();
		b=getll();
		t=get();
		LL int init_pos[51][2],poss[n];
		for (int i = 0; i < n; ++i)
			init_pos[i][0]=getll();
		for (int i = 0; i < n; ++i)
		{
			init_pos[i][1]=getll();
			poss[i] = b-init_pos[i][0]-(t*init_pos[i][1]); 
		}
		LL int count=0,swaps=0,kt=0;
		for (int i=n-1; i>=0 && kt<k; i--)
		{
			if (poss[i] <= 0)
			{
				kt++;
				swaps += count;
			}
			else
			{
				count++;
			}
		}
		if (kt == k)
			printf("Case #%d: %lld\n",z+1,swaps);
		else 
			printf("Case #%d: IMPOSSIBLE\n",z+1);
	}
	return 0;
}