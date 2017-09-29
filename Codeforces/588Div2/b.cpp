#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(LL i=a;i<b;i++)
#define RE(i,a,b) for(LL i=a;i<=b;i++)
#define RR(i,a,b) for(LL i=a;i>b;i--)
#define RRE(i,a,b) for(LL i=a;i>=b;i--)
#define F(i,n) for(LL i=0;i<n;i++)
#define FE(i,n) for(LL i=0;i<=n;i++)
#define FR(i,n) for(LL i=n;i>0;i--)
#define FRE(i,n) for(LL i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <LL, LL>
#define pb push_back
#define ft first
#define sd second
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked


#define NUM 1000000		// The number upto which primes are to be found.
vector <LL> prime;
LL mark[NUM+2];

void sieve()
{
	memset(mark, false, sizeof(mark));
	for (LL i=2; i<=NUM; i++)
	{
		if (!mark[i])
		{
			prime.pb(i);
			for (LL j = i*i; j<=NUM; j+=i)
				mark[j] = true;
		}
	}
}

vector <LL> factors;

int main()
{
	sieve();
	LL n;
	cin >> n;
	F(i,prime.size())
	{
		if (prime[i]*prime[i] > n)
			break;
		if (n%prime[i] == 0)
		{
			while (n%prime[i] == 0)
				n/=prime[i];
			factors.pb(prime[i]);
		}
	}
	if (n!=1)
		factors.pb(n);
	LL ans = 1;
	F(i,factors.size())
	{
		ans *= factors[i];
	}
	cout << ans;
	return 0;
}