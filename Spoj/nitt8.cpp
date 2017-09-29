#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <long long int, long long int>
#define pb push_back
#define ft first
#define sd second
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

pii a[100005];

bool cmp(pii x, pii y)
{
	return x.ft < y.ft;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		LL h;
		get(n);
		F(i,n)
		{
			getll(h);
			a[i] = mp(h,(LL)(i));
		}
		sort(a, a+n, cmp);
		LL maxpos = a[n-1].sd;
		LL minpos = maxpos;
		LL ans = 0;
		FRE(i,n-1)
		{
			maxpos = max(maxpos, a[i].sd);
			minpos = min(minpos, a[i].sd);
			ans = max(ans, (a[i].ft)*(abs(a[i].sd-maxpos)));
			ans = max(ans, (a[i].ft)*(abs(a[i].sd-minpos)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}