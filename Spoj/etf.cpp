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

LL phi[1000005];

void euler()
{
	for (LL i=1; i<=1000000; i++)
		phi[i] = i;
	for (LL i=2; i<=1000000; i++)
	{
		if (phi[i] == i)
		{
			for (LL j=i; j<=1000000; j+=i)
			{
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
}

int main()
{
	int T;
	get(T);
	euler();
	while (T--)
	{
		LL n;
		getll(n);
		printf("%lld\n",phi[n]);
	}
	return 0;
}