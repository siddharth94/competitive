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

LL mod = (LL)(1e9) + 7ll;

struct node
{
	LL sum, add, mul, val;
	int leaves;
	bool reset;

	void init(int a) 
	{
		sum = a;
		add = 0; // to be propogated
		mul = 1; // to be propogated
		val = a; // to be propogated
		reset = false; // to be propogated
		leaves = 1;
	}

	void merge(node l, node r)
	{
		leaves = l.leaves + r.leaves;
		sum = (l.sum + r.sum) % mod;
		add = 0;
		mul = 1;
		val = 0;
		reset = false;
	}

	void split(node *l, node *r)
	{
		if (reset)
		{
			(*l).sum = (((*l).leaves) * val) % mod;
			(*l).add = 0;
			(*l).mul = 1;
			(*l).val = val;
			(*l).reset = true;

			(*r).sum = (((*r).leaves) * val) % mod;
			(*r).add = 0;
			(*r).mul = 1;
			(*r).val = val;
			(*r).reset = true;
			val = 0;
			reset = false;
		}
		(*l).add *= mul; 
		(*l).add %= mod; 
		
		(*r).add *= mul;
		(*r).add %= mod; 
		

		(*l).add += add; 
		(*l).add %= mod; 
		
		(*r).add += add;
		(*r).add %= mod; 
		
		(*l).mul *= mul;
		(*l).mul %= mod;
		
		(*r).mul *= mul;
		(*r).mul %= mod;

		(*l).sum *= mul;
		(*l).sum %= mod;

		(*r).sum *= mul;
		(*r).sum %= mod;
		
		(*l).sum += ((*l).leaves * add) % mod;
		(*l).sum %= mod;
		(*r).sum += ((*r).leaves * add) % mod;
		(*r).sum %= mod;
		
		add = 0;
		mul = 1;
	}
};

LL a[100005];
node stree[405005];

void build(int root, int s, int e)
{
	if (s==e)
	{
		stree[root].init(a[s]);
		return;
	}
	int mid = (s+e) >> 1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);
	stree[root].merge(stree[root*2], stree[root*2+1]);
}

void updatesum(int root, int s, int e, int qs, int qe, LL val)
{
	if (s==qs && e==qe)
	{
		stree[root].add += val;
		stree[root].add %= mod;
		stree[root].sum += (stree[root].leaves * val) % mod;
		stree[root].sum %= mod;
		return;
	}
	
	stree[root].split(&stree[root*2], &stree[root*2+1]);

	int mid = (s+e) >> 1;
	if (qe <= mid)
		updatesum(root*2, s, mid, qs, qe, val);
	else if (qs > mid)
		updatesum(root*2+1, mid+1, e, qs, qe, val);
	else
	{
		updatesum(root*2, s, mid, qs, mid, val);
		updatesum(root*2+1, mid+1, e, mid+1, qe, val);
	}
	stree[root].merge(stree[root*2], stree[root*2+1]);
}

void updatemul(int root, int s, int e, int qs, int qe, LL val)
{
	if (s==qs && e==qe)
	{
		stree[root].sum *= val;
		stree[root].sum %= mod;
		stree[root].mul *= val;
		stree[root].mul %= mod;
		stree[root].add *= val;
		stree[root].add %= mod;
		return;
	}

	stree[root].split(&stree[root*2], &stree[root*2+1]);

	int mid = (s+e) >> 1;
	if (qe <= mid)
		updatemul(root*2, s, mid, qs, qe, val);
	else if (qs > mid)
		updatemul(root*2+1, mid+1, e, qs, qe, val);
	else
	{
		updatemul(root*2, s, mid, qs, mid, val);
		updatemul(root*2+1, mid+1, e, mid+1, qe, val);
	}
	stree[root].merge(stree[root*2], stree[root*2+1]);
}

void reset(int root, int s, int e, int qs, int qe, LL val)
{
	if (s==qs && e==qe)
	{
		stree[root].val = val;
		stree[root].reset = true;
		stree[root].mul = 1;
		stree[root].add = 0;
		stree[root].sum = (stree[root].leaves * val) % mod;
		stree[root].sum %= mod;
		return;
	}

	stree[root].split(&stree[root*2], &stree[root*2+1]);

	int mid = (s+e) >> 1;
	if (qe <= mid)
		reset(root*2, s, mid, qs, qe, val);
	else if (qs > mid)
		reset(root*2+1, mid+1, e, qs, qe, val);
	else
	{
		reset(root*2, s, mid, qs, mid, val);
		reset(root*2+1, mid+1, e, mid+1, qe, val);
	}
	stree[root].merge(stree[root*2], stree[root*2+1]);
}

LL query(int root, int s, int e, int qs ,int qe)
{
	if (s==qs && e==qe)
		return stree[root].sum;

	stree[root].split(&stree[root*2], &stree[root*2+1]);

	int mid = (s+e) >> 1;
	if (qe <= mid)
		return query(root*2, s, mid, qs, qe);
	else if (qs > mid)
		return query(root*2+1, mid+1, e, qs, qe);
	else 
		return ((query(root*2, s, mid, qs, mid) + query(root*2+1, mid+1, e, mid+1, qe)) % mod);
}

int main()
{
	int n,q;
	get(n);
	get(q);
	F(i,n)
		getll(a[i]);
	build(1,0,n-1);
	int x,y;
	LL v;
	F(i,q)
	{
		int t;
		get(t);
		switch(t)
		{
			case 1:
			{
				get(x);
				get(y);
				getll(v);
				x--, y--;
				updatesum(1,0,n-1,x,y,v);
				break;
			}
			case 2:
			{
				get(x);
				get(y);
				getll(v);
				x--, y--;
				updatemul(1,0,n-1,x,y,v);
				break;
			}
			case 3:
			{
				get(x);
				get(y);
				getll(v);
				x--, y--;
				reset(1,0,n-1,x,y,v);
				break;
			}
			case 4:
			{
				get(x);
				get(y);
				x--, y--;
				printf("%lld\n", query(1,0,n-1,x,y));
			}
		}
	}
	return 0;
}