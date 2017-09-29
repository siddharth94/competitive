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

#define MOD 1000000007

int a[105];
map <int,int> nmap;
std::vector<int> pos[102][102][102];
LL dp[105][105];

int main()
{
	int n;
	get(n);
	int count = 1;

	F(i,n)
	{
		get(a[i]);
		if (nmap.find(abs(a[i])) == nmap.end())
		{
			nmap[abs(a[i])] = count++;
			if (a[i] < 0)
				a[i] = -nmap[abs(a[i])];
			else a[i] = nmap[abs(a[i])];
		}
		else
		{
			if (a[i] < 0)
				a[i] = -nmap[abs(a[i])];
			else a[i] = nmap[abs(a[i])];
		}
	}

	F(x,n)
	{
		if (a[x] > 0)
		{
			FE(i,x)
				R(j,x,n)
					pos[i][j][a[x]].pb(x);
		}
	}

	memset(dp, 0LL, sizeof(dp));

	F(i,n+2)
		F(j,i)
			dp[i][j] = 1LL;

	FRE(i,n-1)
	{
		R(j,i,n)
		{
			dp[i][j] += dp[i+1][j];
			dp[i][j] %= MOD;
			if (a[i] < 0)
			{
				int sz = pos[i][j][-a[i]].size();
				F(z,sz)
				{
					dp[i][j] += dp[i+1][pos[i][j][-a[i]][z]-1] * dp[pos[i][j][-a[i]][z]+1][j];
					dp[i][j] %= MOD;
				}
			}
		}
	}

	printf("%lld\n",dp[0][n-1]);

	return 0;
}