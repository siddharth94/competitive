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
#define pii pair <int, int>
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

pii milk[10005];

bool comp(pii a, pii b)
{
	if (a.ft != b.ft)
		return a.ft<b.ft;
	else return a.sd>b.sd;
}

int main()
{
	int n;
	get(n);
	F(i,n)
	{
		get(milk[i].sd);	//gallon
		get(milk[i].ft);	//time limit
	}
	LL sum = 0;
	sort (milk, milk+n, comp);
	F(i,n)
	{
		sum += (LL)milk[i].sd;
		while (i!=n-1 and milk[i].ft == milk[i+1].ft)
			i++;
	}
	printf("%lld\n",sum);
	return 0;
}