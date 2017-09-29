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

#define NUM 1000005		// The number upto which primes are to be found.
vector <LL> prime;
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

struct obj
{
	int num, prime, power;
};

obj cand[500];

bool comp(obj a, obj b)
{
	return a.num < b.num;
}

bool comp2(obj a, int val)
{
	return a.num < val;
}

int main()
{
	sieve();
	
	cand[0].num = 2;
	cand[0].prime = 2;
	cand[0].power = 1;
	
	int idx = 1;
	for (int i=0; i<prime.size(); i++)
	{
		LL power = 2;
		LL tmp = prime[i]*prime[i];
		while(tmp < 1000005)
		{
			LL dsum = (tmp*prime[i] - 1)/(prime[i] - 1);
			if (dsum < 1000000 && !mark[dsum])
			{
				cand[idx].num = tmp;
				cand[idx].prime = prime[i];
				cand[idx].power = power;
				idx++;
			}
			tmp = tmp*prime[i];
			power++;
		}
	}

	sort(cand, cand+idx, comp);
	
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int a,b;
		get(a);
		get(b);
		obj *p = lower_bound(cand, cand+idx, a, comp2);
		int off = (p - cand);
		int count = 0;
		while (off < idx && cand[off].num <= b)
		{
			count++;
			off++;
		}
		printf("%d\n", count);
	}
	return 0;
}