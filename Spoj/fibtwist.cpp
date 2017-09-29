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

int ft[60000000];

int fib(int n,int m)
{
	
	// LL fibt;
	// if (n<60000000)
	// {
	// 	if (ft[n] != 0)
	// 	{
	// 		return ft[n];
	// 	}
	// 	else
	// 	{
	// 		if (ft[n-1] == 0)
	// 		{
	// 			fibt = (fib(n-1,m) + fib(n-2,m))%m;
	// 			fibt += n-1;
	// 			fibt %=m;
	// 			ft[n] = fibt;
	// 		}
	// 		else if (ft[n-2]==0)
	// 		{
	// 			fibt = (ft[n-1] + fib(n-2,m))%m;
	// 			fibt += n-1;
	// 			fibt %= m;
	// 			ft[n] = fibt;
	// 		}
	// 		else 
	// 		{
	// 			fibt = (ft[n-1] + ft[n-2])%m;
	// 			fibt += n-1;
	// 			fibt %= m;
	// 			ft[n] = fibt;
	// 		}
	// 		return ft[n];
	// 	}
	// }
	// else
	// {
	// 	fibt = (fib(n-1,m)+fib(n-2,m))%m;
	// 	fibt += n-1;
	// 	fibt %= m;
	// 	return fibt;
	// }
}

int main()
{
	int T;
	get(T);
	ft[0]=0;
	ft[1]=1;
	ft[2]=2;
	while (T--)
	{
		int n,m;
		get(n);
		get(m);
		printf("%d\n",fib(n,m));
	}
	return 0;
}