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
#define ll long long
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

int a[505];

int gcd (int a, int b)
{
	if (a == 0)
		return b;
	return gcd (b%a, a);
}

ll lcm(int a, int b)
{
	if (a>b) 
		swap(a,b);
	
	int g = gcd(a,b);

	return ((ll)(a)*(ll)(b))/(ll)(g);
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		F(i,n)
			get(a[i]);

		ll ans = 99999999999999999;

		F(i,n)
		{
			R(j,i+1,n)
			{
				ans = min(ans, lcm(a[i], a[j]));
			}
		}	

		printf("%lld\n", ans);
	}
	return 0;
}