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

int h[10005],c[10005];
LL bring_to[10005];
pair <int,int> hc[10005];

bool comp (pair<int,int> i,pair<int,int> j) 
{ return ((i.first)<(j.first)); }

int main()
{
	int T = get();
	while (T--)
	{
		int n = get();
		int cbar = 0;
		LL sighc =0;
		F(i,n)
			h[i] = get();
		F(i,n)
		{
			c[i] = get();
			sighc += h[i]*c[i];
			cbar +=c[i];
			hc[i] = make_pair(h[i],c[i]);
		}
		sort (&hc[0],&hc[n],comp);
		bring_to[0] = sighc - ((hc[0].first)*cbar);

		for (int i=1;i<n;i++)
		{
			int diff_ht = (hc[i].first) - (hc[i-1].first);
			bring_to[i] = bring_to[i-1];
			int j=0,cost=0;
			while (j<i)
				cost += hc[j++].second;
			while (j<n)
				cost -= hc[j++].second;
			bring_to[i] += diff_ht * cost;
			if (bring_to[i] < bring_to[0])
				bring_to[0] = bring_to[i];
		}
		printf("%lld\n",bring_to[0]);
	}
	return 0;
}