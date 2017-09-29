#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
#define F(i,n) for(long long i=0;i<n;i++)
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

inline LL getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
	return x;
}

LL h[100005];
LL ra[100005], la[100005];
stack < LL > r,l;

int main()
{
	LL n;
	while (getll(n) != 0)
	{
		F(i,n)
			getll(h[i]);

		F(i,n)
		{
			while (!r.empty() && h[r.top()]>h[i])
			{
				ra[r.top()] = i-1;
				r.pop();
			}
			r.push(i);

			while (!l.empty() && h[l.top()]>h[n-1-i])
			{
				la[l.top()] = n-i;
				l.pop();
			}
			l.push(n-1-i);
		}

		while (!r.empty())
		{
			ra[r.top()] = n-1;
			r.pop();
		}

		while (!l.empty())
		{
			la[l.top()] = 0;
			l.pop();
		}

		LL maxh = 0;
		F(i,n)
			maxh = max(maxh, (ra[i]-la[i]+1)*h[i]);

		printf("%lld\n", maxh);
	}
	return 0;
}
