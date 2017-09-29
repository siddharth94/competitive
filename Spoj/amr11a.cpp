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

int mat[505][505];
int dp[505][505];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int r,c;
		get(r);
		get(c);	
		F(i,r)
			F(j,c)
			{
				get(mat[i][j]);
				dp[i][j] = 1000000000;
			}
		dp[r-1][c-1] = 1;
		for (int i=r-1; i>=0; i--)
			for (int j=c-1; j>=0; j--)
			{
				dp[i-1][j] = min(dp[i][j]-mat[i-1][j], dp[i-1][j]);
				if (dp[i-1][j] <= 0)
					dp[i-1][j] = 1;

				dp[i][j-1] = min(dp[i][j]-mat[i][j-1], dp[i][j-1]);
				if (dp[i][j-1] <= 0)
					dp[i][j-1] = 1;
			}
		if (dp[0][0] <= 0)
			dp[0][0] = 1;
		printf("%d\n", dp[0][0]);
	}	
	return 0;
}