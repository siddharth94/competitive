#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

LL gcd(LL a,LL b)
{
	return (a==0)?b:gcd(b%a,a);
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		LL n,m;
		getll(n);
		getll(m);
		if (((n & 1) == 1) && ((m & 1) == 1))
		{
			LL num = ((m*n)-1)/2;
			LL den = m*n;
			LL g = gcd(num , den);
			num/=g;
			den/=g;
			printf("%lld/%lld\n", num,den);
		}	
		else printf("1/2\n");
	}
	return 0;
}