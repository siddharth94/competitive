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

#define NUM 10000005ll		// The number upto which primes are to be found.
int sm_prime[NUM+5];
int a[100005];
int dp[10000005];

vector <int> factors;

void sieve()
{
	memset(sm_prime, 0, sizeof(sm_prime));
	sm_prime[1] = 1;

	for (LL i=2; i<=NUM; i++)
	{
		if (sm_prime[i] == 0)
		{
			sm_prime[i] = i;
			for (LL j = i*i; j<=NUM; j+=i)
				if (sm_prime[j] == 0)
					sm_prime[j] = i;
		}
	}
}

void factorize(int num)
{
	factors.clear();
	while (num != 1)
	{
		int f = sm_prime[num];
		factors.push_back(f);
		while (num%f == 0)
			num /= f;
	}
}

int main()
{
	sieve();
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		memset(dp, 0, sizeof dp);

		F(i,n)
			get(a[i]);

		int m = 0;
		int ans = 0;
		F(i,n)
		{
			factorize(a[i]);
			m = 0;

			for (int j=0; j<factors.size(); j++)
				m = max(m, dp[factors[j]]);

			for (int j=0; j<factors.size(); j++)
				dp[factors[j]] = m+1;

			ans = max(m+1,ans);			
		}

		printf("%d\n", ans);
	}
	return 0;
}