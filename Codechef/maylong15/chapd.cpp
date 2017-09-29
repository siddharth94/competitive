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

LL gcd(LL a, LL b)
{
	(a>b) ? swap(a,b) : swap(a,a);
	return (b%a == 0) ? a : gcd(b%a, a);
}

int main()
{
	int T;
	get(T);
	
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL a,b;
		getll(a);	
		getll(b);

		LL hcf = a;

		while (b != 1 && hcf != 1)
		{
			hcf = gcd(a,b);
			if (hcf == 1)
				break;
			while (b%hcf == 0)
				b /= hcf;
			a = hcf;
		}

		if (hcf == 1 && b != 1)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}