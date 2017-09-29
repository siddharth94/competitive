#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
#define pb push_back
#define ft first
#define sd second
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define get(Z) scanf("%d",&Z)

int a[10000005];
int dp[1005];
int f[500];

int fb(int n)
{
	// memset(dp,0,sizeof(dp));
	int ma=0;
	dp[0] = a[f[0]];
	for (int i=1; i<2*n; i++)
	{
		dp[i] = max(a[f[i]]+dp[i-1], a[f[i]]);
		if (dp[i] > ma)
			ma = dp[i];
	}
	return ma;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		// memset(a,0,sizeof(a));
		// memset(f,0,sizeof(f));
		int n,x,y;
		get(n);
		F(i,n)
		{
			get(x);
			get(y);
			f[i] = x;
			f[i+n] = y;
			a[x] = 1;
			a[y] = -1;
		}
		sort(f,f+2*n);
		printf("%d\n",fb(n));
	}
	return 0;
}