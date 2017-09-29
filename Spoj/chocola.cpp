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

LL x[1005],y[1005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL m,n,tmp;
		getll(m);
		getll(n);
		m--,n--;
		F(i,m)
			getll(x[i]);
		F(i,n)
			getll(y[i]);
		sort(x,x+m);
		sort(y,y+n);

		LL xfac, yfac, ans = 0;
		xfac = yfac = 1;
		int xind, yind;
		xind = m-1;
		yind = n-1;
	
		while (xind+1 && yind+1)
		{
			if (x[xind] > y[yind])
			{
				ans += xfac*x[xind];
				yfac++;
				xind--;
			}
			else
			{
				ans += yfac*y[yind];
				xfac++;
				yind--;
			}
		}

		while (xind+1)
		{
			ans += xfac*x[xind];
			xind--;
		}
		while(yind+1)
		{
			ans += yfac*y[yind];
			yind--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}