#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int p1[10005],p2[10005];
int out[20010];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n;
		get(n);
		FE(i,n)
			get(p1[i]);
		FE(i,n)
			get(p2[i]);
		FE(k,n)
			for (int i=0,j=k;i<=k;i++,j--)
			{
				if (p1[i] == 0 || p2[j] == 0)
					continue;
				out[k] += (p1[i]*p2[j]);
			}
		for(int k=1;k<=n;k++)
			for (int i=k,j=n; i<=n;i++,j--)
			{
				if (p1[i] == 0 || p2[j] == 0)
					continue;
				out[n+k] += (p1[i]*p2[j]);
			}
		int ord = (2*n)+1;
		F(i,ord-1)
			printf("%d ",out[i]);
		printf("%d",out[ord-1]);
		printf("\n");
	}
	return 0;
}