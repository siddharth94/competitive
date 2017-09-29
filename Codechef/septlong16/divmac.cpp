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

int a[100005];
int stree[400005];

#define NUM 1000000		// The number upto which primes are to be found.
vector <int> prime;
int mark[NUM+2];
vector <int> divisor[1000005];

void sieve()
{
	memset(mark, false, sizeof(mark));
	divisor[1].pb(1);
	for (int i=2; i<=NUM; i++)
	{
		if (!mark[i])
		{
			prime.pb(i);
			for (int j = i; j<=NUM; j+=i)
			{
				mark[j] = true;
				divisor[j].pb(i);
			}
		}
	}
}

void build(int root, int s, int e)
{
	if (s==e)
	{
		stree[root] = divisor[a[s]][0];
		return;
	}

	int mid = (s+e)>>1;

	build(root*2, s, mid);
	build(root*2+1, mid+1, e);

	stree[root] = max(stree[root*2], stree[root*2+1]);
	return;
}

int query(int root, int s, int e, int l, int r)
{
	if (s==l && e==r)
		return stree[root];

	int mid = (s+e)>>1;

	if (l>mid)
		return query(root*2+1, mid+1, e, l, r);
	else if (r<=mid)
		return query(root*2, s, mid, l, r);
	else return max(query(root*2, s, mid, l, mid), query(root*2+1, mid+1, e, mid+1, r));
}

void update(int root, int s, int e, int l, int r)
{
	if (stree[root] == 1)
		return;
	if (s==e)
	{
		a[s] = a[s]/divisor[a[s]][0];
		stree[root] = divisor[a[s]][0];
		return;
	}

	int mid = (s+e)>>1;

	if (r<=mid)
		update(root*2, s, mid, l, r);
	else if (l>mid)
		update(root*2+1, mid+1, e, l, r);
	else
	{
		update(root*2, s, mid, l, mid);
		update(root*2+1, mid+1, e, mid+1, r);
	}

	stree[root] = max(stree[root*2], stree[root*2+1]);
}

int main()
{
	int T;
	get(T);
	sieve();	
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;
		get(n);
		get(m);

		F(i,n)
			get(a[i]);

		build(1,0,n-1);

		F(i,m)
		{
			int type,l,r;
			get(type);
			get(l);
			get(r);
			l--;
			r--;

			if (type)
			{
				printf("%d ", query(1,0,n-1,l,r));
			}
			else
			{
				update(1,0,n-1,l,r);
			}
		}
		printf("\n");
	}
	return 0;
}