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

int prime[1000006];
LL p_list[90000];
int k;

void sieve()
{
	prime[0]=prime[1]=-1;
	for (LL i=2;i<1000000;i++)
	{
		if (prime[i]!=-1)
		{
			p_list[k++]=i;
			LL tmp =i;
			tmp+=i;
			while (tmp<1000000)
			{
				prime[tmp]=-1;
				tmp +=i;
			}
		}
	}
}

int main()
{
	sieve();
	LL n;
	getll(n);
	LL sq = sqrt(n);
	printf("%lld\n",sq);
	for (int i=0;i<k && p_list[i]<sq;i++)
	{
		if (n%p_list[i] == 0)
		{
			printf("%lld\n",p_list[i]);
			n/=p_list[i];
			while (n%p_list[i] == 0)
				n/=p_list[i];
			if (n==1)
				break;
		}
	}
	if (n!=1)
		printf("%lld\n",n);
	return 0;
}