#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
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

int a[1025];
int dp[1005][1025];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n, k;
		get(n);
		get(k);
		F(i,n)
			get(a[i]);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		RE(i,1,n)
		{
			F(j,1024)
			{
				dp[i][j] = dp[i-1][j] | dp[i-1][j^a[i-1]];
			}
		}
		int m = dp[n][0]*k;
		F(i,1024)
		{
			m = max(m,dp[n][i]*(i^k));
		}
		printf("%d\n",m);
	}
	return 0;
}