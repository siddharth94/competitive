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
	printf("1\n");
	printf("10000\n");
	int count=0;
	for (int i=1;i<=5000;i++)
	{
		printf("%d %d ",i,10001-i);
		count+=2;
	}
	printf("\n10000\n");
	for (int i=1000;i<6000;i++)
	{
		printf("0 %d %d\n",i,10000-i);
		printf("1 %d\n",i);
	}
	return 0;
}