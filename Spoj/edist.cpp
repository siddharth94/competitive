#include <bits/stdc++.h>
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

int dp[2005][2005];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		string a,b;
		cin >> a >> b;

		int la = a.length();
		int lb = b.length();

		FE(i,la)
		{
			FE(j,lb)
			{
				if (i==0)
					dp[i][j] = j;
				else if (j==0)
					dp[i][j] = i;
				else
				{
					if (a[i-1] == b[j-1])
						dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]);
					else
						dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				}
			}
		}

		printf("%d\n",dp[la][lb]);
	}
	return 0;
}