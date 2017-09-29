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

LL digit_sum(LL n)
{
	int sum=0;
	while (n!=0)
	{
		int rem = n%10;
		n/=10;
		sum+=rem;
	}
	return sum;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		LL n;
		getll(n);
		LL sum = digit_sum(n);
		while (n%sum != 0)
		{
			n++;
			sum = digit_sum(n);
		}
		printf("%lld\n",n);
	}
	return 0;
}