#include <bits/stdc++.h>
using namespace std;

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

LL mod;
int mark[100005];
vector < LL > prime;

struct node
{
	LL prod, i, j;

	void init(int idx)
	{
		prod = prime[idx];
		i = idx;
		j = idx;
	}

	void merge(node l, node r)
	{
		prod = (l.prod * r.prod)%mod;
		i = l.i;
		j = r.j;
	}

}tree[400005];

void sieve()
{
	memset(mark, 0, sizeof(mark));
	for (LL i=2; i<100002; i++)
	{
		if (mark[i] == 0)
		{
			for (LL j=i*i; j<100002; j+=i)
				mark[j] = 1;
			prime.pb(i);
		}
	}
}

void build(int root, int s, int e)
{
	if (s==e)
	{
		tree[root].init(s);
		return;
	}
	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1,  mid+1, e);
	tree[root].merge(tree[root*2], tree[root*2+1]);
}

LL query(int root, int s, int e, int x, int y)
{
	if (s==x && y==e)
		return tree[root].prod;
	int mid = (s+e)>>1;
	if (x>mid)
		return query(root*2+1, mid+1, e, x, y);
	else if (y<mid+1)
		return query(root*2, s, mid, x,y);
	else return (query(root*2,  s, mid, x, mid)*query(root*2+1, mid+1, e, mid+1, y))%mod;
}

int main()
{
	mod = 1e9+7;
	sieve();
	int s = prime.size();
	int q;
	get(q);
	build(1,0,s);
	LL a1, a2;
	vector < LL > :: iterator x,y;
	F(i,q)
	{
		getll(a1);
		getll(a2);
		x = lower_bound(prime.begin(), prime.end(), a1);
		y = lower_bound(prime.begin(), prime.end(), a2);
		if (*y != a2)
			y--;
		int st = x - prime.begin();
		int ed = y - prime.begin();
		printf("%lld\n",query(1,0,s-1,st,ed));
	}
	return 0;
}