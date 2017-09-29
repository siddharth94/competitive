#include <bits/stdc++.h>
using namespace std;

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

int a[1000005];

LL f(LL n)
{
	LL m;
	if (n < 1000000 && a[n] != -1)
		return a[n];
	else
	{
		m = max(n,f(n/2)+f(n/3)+f(n/4));
		if (n<1000000)
			a[n] = m;
		return m;
	}
}

int main()
{
	memset(a,-1,sizeof(a));
	a[0] = 0;
	LL n;
	while(scanf("%lld",&n) != EOF)
		printf("%lld\n",f(n));
	return 0;
}