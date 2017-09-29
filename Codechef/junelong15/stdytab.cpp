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

LL mod = (LL)(1000000000);

LL ncr[5505][5505];
LL tab[2005][2005];

void calc()
{
	ncr[0][0] = 1;
	for (int n=1; n<=5500; n++)
	{
		ncr[n][0] = 1;
		for (int r=1; r<=n; r++)
		{
			ncr[n][r] = (ncr[n-1][r-1] + ncr[n-1][r])%mod;
		}
	}
}

int main()
{
	calc();
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL n,m;
		getll(n);
		getll(m);
		LL ans = 1;
		
		for (int i=0; i<n; i++)
			tab[i][0] = 1;
		for (int i=0; i<=m; i++)
			tab[n-1][i] = ncr[m+i-1][i];
		
		for (int i=1; i<=m; i++)
		{
			LL prod = tab[n-1][i];
			for (int j=n-2; j>=0; j--)
			{
				tab[j][i] = tab[j+1][i] + tab[j][i-1];
				tab[j][i] %= mod;
				prod *= tab[j][i];
				prod %= mod;
			}
			ans += prod;
			if (ans >= mod)
				ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}