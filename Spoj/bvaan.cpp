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

int dp[105][105][105];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		memset(dp, 0, sizeof(dp));
		char s1[105], s2[105];
		int k;
		scanf("%s", s1);	
		scanf("%s", s2);
		get(k);
		int n1 = strlen(s1);
		int n2 = strlen(s2);
		for (int i=0; i<=n1; i++)
		{
			for (int j=0; j<=n2; j++)
			{
				for (int z=1; z<=k; z++)
				{
					if (i==0 || j==0)
					{
						dp[i][j][z] = 0;
						continue;
					}
					if (s1[i-1] == s2[j-1])
					{
						if (z>1 && dp[i-1][j-1][z-1] != 0)
							dp[i][j][z] = max((int)(s1[i-1]) + dp[i-1][j-1][z-1], max(dp[i-1][j][z], dp[i][j-1][z]));
						else if (z==1)
							dp[i][j][z] = max((int)(s1[i-1]), max(dp[i-1][j][1], dp[i][j-1][1]));
						else
							dp[i][j][z] = 0;
					}
					else
					{
						dp[i][j][z] = max(dp[i-1][j][z], dp[i][j-1][z]);
					}
				}
			}
		}
		printf("%d\n", dp[n1][n2][k]);
	}
	return 0;
}