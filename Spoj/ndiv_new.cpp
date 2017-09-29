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

#define NUM 100005		// The number upto which primes are to be found.
vector <int> prime;
bool mark[NUM+2];

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

int numdiv[10005];
int leftnum[100005];

int highest_power(int base, int e)
{
	int hp = 0;
	while (base%e == 0)
	{
		base /= e;
		hp++;
	}
	return hp;
}

int main()
{
	sieve();
	int a,b,n;
	get(a);
	get(b);
	get(n);
	for (int i=0; i<(b-a+1); i++) 
	{
		numdiv[i] = 1;
		leftnum[i] = a+i;
	}

	for (int i=0; i<prime.size(); i++)
	{
		int rem = (prime[i] - (a%prime[i])) % prime[i];
		if (a+rem > b)
			continue;
		int next = a+rem;
		while (next <= b)
		{
			int hp = 0;
			while (leftnum[next-a] % prime[i] == 0)
			{
				leftnum[next-a] /= prime[i];
				hp++;
			}
			numdiv[next-a] *= (highest_power(next,prime[i])+1);
			next += prime[i];
		}
	}
	
	int ans = 0;
	for (int i=0; i<(b-a+1); i++)
	{
		if (leftnum[i] != 1) {
			numdiv[i] *= 2;
		}
		if (numdiv[i] == n)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}