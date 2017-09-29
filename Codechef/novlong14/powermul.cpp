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
#define pii pair < long long, long long >
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

#define NUM 100001l		// The number upto which primes are to be found.
vector < LL > prime;
int mark[NUM+2];

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

vector < pii > factor[100005];
int num[100005];

void factorize()
{
	F(i,100005)
		num[i] = i;
	size_t n = prime.size();
	for (size_t i=0; i<n; i++)
	{
		int k=1;
		LL pow = prime[i];
		while(pow < 100001)
		{
			LL z = 0;
			for (LL j=pow; j<=100001; j+=prime[i])
			{
				if (k==1)
				{
					factor[j].pb(mp(prime[i],0));
					factor[j].back().sd += z+j;
					num[j] /= prime[i];
					z+=j;
				}
				else if (num[j]%prime[i] == 0)
				{
					((factor[j]).back()).sd += z+j;
					z+=j;
					num[j] /= prime[i];
				}
				else
				{
					factor[j].back().sd += z;
				}
			}
			k++;
			pow *= prime[i];
		}
	}
}

LL oriprod[10000];
LL den[10000];

LL power (LL b, LL p, LL mod)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	LL p1 = p,ans=1;
	if (p%2 == 0)
	{
		ans = power(b,p/2,mod)%mod;
		ans = (ans * ans)%mod;
	}
	else if (p%2 == 1)
	{
		ans = power (b,p/2,mod)%mod;
		ans = (((ans * ans) %mod) *b)%mod;
	}
	return ans;
}

bool comp( pii a, LL val)
{
	return a.ft < val;
}

int main()
{
	sieve();
	factorize();
	int creep = prime.size();
	int T;
	LL rem, numb, r, nr, jhabra;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL n,m,q;
		getll(n);
		getll(m);
		getll(q);
		for (int i=0; prime[i] <= n; i++)
		{
			numb = prime[i]*(n/prime[i]);
			vector < pii > :: iterator it = lower_bound(factor[numb].begin(), factor[numb].end(), prime[i], comp);
			oriprod[i] = it->sd;
		}
		while(q--)
		{
			getll(r);
			nr = n-r;
			jhabra = max(r,nr);
			memset(den, 0, sizeof(den));
			for (int i=0; prime[i] <= jhabra; i++)
			{
				if (prime[i] <= r)
				{
					numb = prime[i]*(r/prime[i]);
					vector < pii > :: iterator it = lower_bound(factor[numb].begin(), factor[numb].end(), prime[i], comp);
					den[i] = it->sd;
				}

				if (prime[i] <= nr)
				{
					numb = prime[i]*(nr/prime[i]);
					vector < pii > :: iterator it = lower_bound(factor[numb].begin(), factor[numb].end(), prime[i], comp);
					den[i] += it->sd;
				}
			}
			LL ans = 1;
			for (int i=0; prime[i]<=n; i++)
			{
				ans *= power(prime[i],oriprod[i]-den[i],m);
				ans %= m;
			}
			printf("%lld\n",ans);
		}
	}

	// LL tot = 0;
	// int max = 0;
	// F(i,100000)
	// {
	// 	cout << "\n" << i << ":\t\t";
	// 	int n = factor[i].size();
	// 	if (n>max)
	// 		max = n;
	// 	tot += n;
	// 	F(j,n)
	// 	{
	// 		cout << "(" << factor[i][j].ft << "," << factor[i][j].sd << ") ";
	// 	}
	// }
	// cout << endl << max << endl;
	return 0;
}