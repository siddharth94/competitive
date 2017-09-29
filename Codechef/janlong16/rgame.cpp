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

LL a[100005];
LL parr[100005];
LL psum[100005];

int main()
{
	LL mod = (LL)(1e9+7);
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		LL sum = 0;

		FE(i,n)
		{
			getll(a[i]);
			sum += a[i];
		}

		LL p = 1;

		FR(i,n)
		{
			parr[i] = (a[i]*p);
			p <<= 1;
			psum[i] = (i==n) ? parr[i] : psum[i+1]+parr[i];

			if (p >= mod)
				p %= mod;

			if (parr[i] >= mod)
				parr[i] %= mod;

			if (psum[i] >= mod)
				psum[i] %= mod;
		}

		LL ans = 0;

		ans += (a[0]*psum[1]*2) % mod;

		LL f = 2;

		R(i,1,n)
		{
			ans += (a[i]*((psum[i+1]*f)%mod)) % mod;
			f <<= 1;
			ans %= mod;
			f %= mod;
			if (ans < 0)
			{
				cout << "small\n";
			}
		}

		printf("%lld\n", ans);
	}
	return 0;
}