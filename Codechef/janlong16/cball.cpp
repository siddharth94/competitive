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

#define NUM 10000		// The number upto which primes are to be found.
vector <int> prime;
int mark[NUM+2];

vector <int> factors[10005];

void sieve()
{
	memset(mark, false, sizeof(mark));
	for (int i=2; i<=NUM; i++)
	{
		if (!mark[i])
		{
			prime.pb(i);
			for (int j = i; j<=NUM; j+=i)
			{
				mark[j] = true;
				factors[j].pb(i);
			}
		}
	}
}

int a[10005];

int main()
{
	sieve();	// 1229 primes
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		LL inc = 0;
		LL n0 = 0;

		F(i,n)
		{
			get(a[i]);

			if (a[i] == 1)
			{
				a[i]++;
				inc++;
			}
		
			if (i>0 && a[i-1] > a[i])
			{
				inc += a[i-1]-a[i];
				a[i] = a[i-1];
			}

			if (a[i]%2)
				n0++;
		}

		F(i,prime.size())
		{
			if (prime[i] == 2)
				continue;
			LL nans = 0;
			F(x,n)
			{
				nans += (prime[i] - (a[x]%prime[i]) )%prime[i];
				if (nans > n0)
					break;
			}
			if (nans < n0)
				n0 = nans;
		}

		printf("%lld\n", inc+n0);
	}
	return 0;
}