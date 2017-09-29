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

struct timing{
	int s,e;
	LL cum, t;
}cls[100005];

bool cmp(timing a, timing b)
{
	return a.s < b.s;
}

bool ccmp(timing a, int val)
{
	return a.s < val;
}

LL mod = (LL)(1e8);

int main()
{
	while (1)
	{
		int n;
		get(n);
		if (n==-1)
			break;
		F(i,n)
		{
			get(cls[i].s);
			get(cls[i].e);
			cls[i].cum = 0;
			cls[i].t = 0;
		}
		sort(cls,cls+n,cmp);
		cls[n-1].t = 1;
		cls[n-1].cum = 1;
		FRE(i,n-2)
		{
			int k = cls[i].e;
			timing *p = lower_bound(cls,cls+n,k,ccmp);

			if (p == cls+n)
				cls[i].t = 1;
			else
			{
				cls[i].t = 1+cls[(int)(p-cls)].cum;
				if (cls[i].t >= mod)
					cls[i].t %= mod;
			}

			cls[i].cum = cls[i].t + cls[i+1].cum;
			if (cls[i].cum >= mod)
				cls[i].cum %= mod;
		}

		printf("%08lld\n", cls[0].cum);
	}
	return 0;
}