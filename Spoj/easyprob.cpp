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

int find(int a)
{
	if (a<=2)
	{
		if (a!=1)
			printf("%d",a);
		//else printf("(0)");
		return 0;
	}
	int k=1,power=0;
	while (k<=a)
	{
		power++;
		k = k<<1;
	}
	k = k>>1;
	power--;
	printf("2");
	if (power != 1)
		printf("(");
	find(power);
	a -= k;
	if (a!=0)
	{
		if (power!=1)
		{
			printf(")+");
			if (a!=1)
				find(a);
			else printf("2(0)");
		}
		else printf("+2(0)");
		// find(a);
	}
	else if (power != 1)
		printf(")");
	return 0;
}

int main()
{
	int a[]={137,1315,73,136,255,1384,16385};
	F(i,7)
	{
		printf("\n%d=",a[i]);
		find(a[i]);
		// printf("\n");
	}
	return 0;
}