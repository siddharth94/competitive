#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
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

bool valid(LL t)
{
	while (t>0)
	{
		int dig = t%10;
		t/=10;
		if (dig!=0 && dig!=1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	for (LL i=1; i<=20000; i++)
	{
		for (LL j=1; ; j++)
		{
			if (valid (i*j))
			{
				printf ("%lld * %lld = %lld\n", i,j,i*j);
				break;
			}
		}
	}
	return 0;
}