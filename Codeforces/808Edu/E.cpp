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
#define get(x) scanf("%lld", &x)
#define getll(x) scanf("%lld", &x)

struct a
{
	LL c;
	LL w1;
	LL w2;
} dp[300005];

vector <LL> cost[4];

int main()
{
	cost[1].clear();
	cost[2].clear();
	cost[3].clear();

	LL n,m;
	get(n);
	get(m);

	F(i,n)
	{
		LL w,c;
		get(w);
		get(c);
		cost[w].pb(c);
	}

	sort(cost[1].begin(), cost[1].end(), greater<LL>());
	sort(cost[2].begin(), cost[2].end(), greater<LL>());
	sort(cost[3].begin(), cost[3].end(), greater<LL>());

	LL s1,s2,s3;
	s1 = cost[1].size();
	s2 = cost[2].size();
	s3 = cost[3].size();

	dp[0] = {0,0,0};

	if (dp[0].w1 < s1)
		dp[1] = {cost[1][0], 1, 0};
	else
		dp[1] = {0,0,0};

	struct a best;
	best.c = dp[1].c;
	best.w1 = dp[1].w1;
	best.w2 = dp[1].w2;

	for (LL i=2; i<=m; i++)
	{
		/*
		i-1 + w1
		i-2 + w1 + w1
		i-2 + w2
		*/

		LL x,y,z;
		x = y = z = 0;

		dp[i].c = best.c;
		dp[i].w1 = best.w1;
		dp[i].w2 = best.w2;

		if (dp[i-1].w1 < s1)
			x = dp[i-1].c + cost[1][dp[i-1].w1];
		if (dp[i-2].w1 + 1 < s1)
			y = dp[i-2].c + cost[1][dp[i-2].w1] + cost[1][dp[i-2].w1 + 1];
		if (dp[i-2].w2 < s2)
			z = dp[i-2].c + cost[2][dp[i-2].w2];

		if (x>y && x>z)
		{
			dp[i].c = x;
			dp[i].w1 = dp[i-1].w1 + 1;
			dp[i].w2 = dp[i-1].w2;
		}
		else if (y>z)
		{
			dp[i].c = y;
			dp[i].w1 = dp[i-2].w1 + 2;
			dp[i].w2 = dp[i-2].w2;
		}
		else
		{
			dp[i].c = z;
			dp[i].w1 = dp[i-2].w1;
			dp[i].w2 = dp[i-2].w2 + 1;
		}

		if (dp[i].c > best.c)
		{
			best.c = dp[i].c;
			best.w1 = dp[i].w1;
			best.w2 = dp[i].w2;
		}
		else
		{
			dp[i].c = best.c;
			dp[i].w1 = best.w1;
			dp[i].w2 = best.w2;
		}
	}

	LL ans = dp[m].c;
	LL sum = 0ll;

	for (LL i=0; i<s3 && i<m; i++)
	{
		sum += cost[3][i];
		if (m-3*(i+1) >= 0)
			ans = max(ans, sum + dp[m-3*(i+1)].c);	
	}

	cout << ans << endl;

	return 0;
}