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

vector < pair<LL,LL> > expo[42];
vector < pair<LL,LL> > texpo[42];

void fill_expo()
{
	for (LL i=1; i<=1000000; i++)
	{
		LL p = i;
		for (int j=2; j<=40; j++)
		{
			p *= i;
			if (p > 1000000000000ll)
				break;
			expo[j].push_back(mp(p,i));
			texpo[j].pb(mp(2ll*p,i));
		}
	}
}

LL power (LL b, LL p, LL mod)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	
	LL p1 = p,ans=1;

	if (p%2 == 0)
	{
		ans = power(b,p/2,mod);
		if (ans > mod)
			return mod+2;
		ans = (ans * ans);
	}
	else if (p%2 == 1)
	{
		ans = power (b,p/2,mod);
		if (ans > mod)
			return mod+2;
		ans = (((ans * ans)) *b);
	}
	
	return ans;
}

LL search_base(LL n, LL p, LL mul)
{
	LL l,r;
	l = 2;
	r = n;

	LL mid;

	LL r;

	while (l<r)
	{
		mid = (l+r)>>1;

		r = power(mid,p,n);

		if (r*mul < n)
			l = mid;
		else if (r*mul >= n)
			r = mid-1;
	}



}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL n;
		getll(n);

		if (n==0)
		{
			printf("0\n");
			continue;
		}
		else if (n==1)
		{
			printf("INFINITY\n");
			continue;
		}

		LL f1,f2;
		LL ans = 0;

		for (int i=1; i<=40; i++)
		{
			f1 = search_base(n,i,1); // k^i <= n
			f2 = search_base(n,i,2); // 2*k^i <= n
			if (f1 == -1 || f2 == -1)
				break;
			ans += f1 - f2;
		}	

		printf("%lld\n", ans);
	}
	return 0;
}