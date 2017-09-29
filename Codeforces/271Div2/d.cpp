#include <bits/stdc++.h>
using namespace std;

#define get(n) scanf("%d",&n);
#define pii pair<int, int>
#define F(i,n) for (int i=0; i<n; i++)

pii q[100005];
long long dp[100005];

int main()
{
	int t,k;
	get(t);
	get(k);
	long long mod = 1000000007;

	int max = -1, a,b;

	F(i,t)
	{
		get(a);
		get(b);
		q[i] = make_pair(a,b);
		if (max < b)
			max = b;
	}

	F(i,k)
		dp[i] = 1;

	for (int i=k; i<=max; i++)
		dp[i] = (dp[i-1] + dp[i-k])%mod;

	for (int i=2; i<=max; i++)
		dp[i] = (dp[i] + dp[i-1])%mod;

	dp[0] = 0;
	long long sum;

	F(i,t)
	{
		sum = (dp[q[i].second] - dp[q[i].first-1]);
		while (sum < 0)
			sum+=mod;
		printf("%lld\n",sum);
	}
	return 0;
}