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

LL a[100005], s[100005], e[100005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		F(i,n)
			getll(a[i]);

		e[0] = a[0];
		s[n-1] = a[n-1];
		LL msum = max(e[0],s[n-1]);

		for(int i=1; i<n; i++)
		{
			e[i] = (e[i-1] > 0) ? e[i-1] + a[i] : a[i];
			msum = max(e[i], msum);
		}

		for(int i=n-2; i>=0; i--)
		{
			s[i] = (s[i+1] > 0) ? s[i+1] + a[i] : a[i]; 
			msum = max(s[i], msum);
		}

		for(int i=1; i<n-1; i++)
		{
			msum = max(s[i+1] + e[i-1], msum);
		}

		printf("%lld\n", msum);
	}
	return 0;
}