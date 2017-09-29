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
#define LL unsigned long long
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

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

#define NUM 65		// The number upto which primes are to be found.

vector <int> prime;
int mark[NUM+2];

void sieve()
{
	memset(mark, false, sizeof(mark));
	for (int i=2; i<=NUM; i++)
	{
		if (!mark[i])
		{
			prime.pb(i);
			for (int j = i*i; j<=NUM; j+=i)
				mark[j] = true;
		}
	}
}

LL ncr[65][65];

void comb()
{
	ncr[1][0] = ncr[1][1] = ncr[0][0] = 1;
	for (int i=2; i<=64; i++)
	{
		ncr[i][0] = ncr[i][i] = 1;
		for (int j=1; j<i; j++)
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
	}
}

LL find (LL a, int m)
{
	int n = prime.size();
	LL ans = 0;
	int sbits = __builtin_popcountll(a);
	LL k = 1, i = 1;
	while (i<=m)
	{
		if (!(k&a))
		{
			for (int j=0; j<n; j++)
			{
				if (prime[j]-sbits-1 <= i-1 && prime[j]-sbits-1 >= 0)
					ans += ncr[i-1][prime[j]-sbits-1];
			}
		}
		else sbits--;
		k <<=1;
		i++;
	}
	return ans;
}

LL count (int k)
{
	LL ans = 0;
	int n = prime.size();
	for (int i=0; i<n; i++)
	{
		if (prime[i]-1 <= k)
			ans += ncr[k][prime[i]-1];
	}
	return ans;
}

int main()
{
	sieve();
	comb();
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL a,b;
		getll(a);
		getll(b);
		// scanf("%llu %llu", &a, &b);
		int m,n;
		m = (int)log2(a) + 1;
		n = (int)log2(b) + 1;
		LL cts = find(a,m);
		LL cte = find(b,n);
		if (*(lower_bound(prime.begin(),prime.end(),__builtin_popcountll(a))) == __builtin_popcountll(a) )
			cts++;
		for (int i=m+1; i<=n; i++)
			cts += count(i-1);
		cts -= cte;
		printf("%llu\n",cts);
	}
	return 0;
}