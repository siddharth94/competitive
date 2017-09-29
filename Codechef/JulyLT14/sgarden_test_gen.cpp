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
	int a[1000];
	unsigned long long p[]={2,3,5,7,11,  13,17,19,23,29  ,31,37,41,43,47,   53,59,61,67,71   ,73,79};
	int sum = 0,prev = p[0];
	int i = 1;
	for(int z=0; z<22; )
	{
		// for (int i=1; i<1000; i++)
		// {
			sum += prev;
			printf("%d ",sum);
			while (i<sum)
				printf("%d ",i++);
			i++;
			prev = p[++z];
		// }
	}
	return 0;
}