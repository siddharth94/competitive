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

int main()
{
	int k=1;
	printf("p[]={2");
	int sq = sqrt(100000);
	// int sq = 100000;
	for(int i=3;i<sq;i++)
	{
		bool flag=true;
		for (int j=2;j*j<=i;j++)
		{
			if (i%j == 0)
			{
				flag=false;
				break;
			}
		}
		if (flag)
		{
			printf(",%d",i);
			k++;
		}
	}
	printf("}\nTotal primes: %d",k);
	return 0;
}