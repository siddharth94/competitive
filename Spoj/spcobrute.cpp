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

int main()
{
	sieve();
	LL a,b;
	getll(a);
	getll(b);
	LL count = 0;
	for (LL i=a; i<=b; i++)
	{
		int k = __builtin_popcountll(i);
		if (*(lower_bound(prime.begin(), prime.end(), k)) == k)
		{
			count++;
			cout << i << '\t';
		}
	}
	cout << endl << count << endl;
	return 0;
}