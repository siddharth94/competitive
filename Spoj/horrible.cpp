#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
#define pii pair <int, int>
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

struct node
{
	LL sum, incr; 
	LL n_child;

	void init()
	{
		sum = 0;
		n_child = 1;
		incr = 0;
	}

	void merge(node l, node r)
	{
		sum = l.sum + r.sum;
		n_child = l.n_child + r.n_child;
	}

}tree[500005];

void build(int root, int s, int e)
{
	if (s==e)
	{
		tree[root].init();
		return;
	}
	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);
	tree[root].merge(tree[root*2],tree[root*2+1]);
}

LL query(int root, int s, int e, int i, int j)
{
	if (s==i && e==j)
		return tree[root].sum;

	if (tree[root].incr > 0 && tree[root].n_child > 1)
	{
		tree[root*2].incr += tree[root].incr;
		tree[root*2+1].incr += tree[root].incr;
		tree[root*2].sum += tree[root].incr * tree[root*2].n_child;
		tree[root*2+1].sum += tree[root].incr * tree[root*2+1].n_child;
		tree[root].incr = 0;
	}

	int mid = (s+e)>>1;
	if (j<mid+1)
		return query(root*2, s, mid, i, j);
	else if (i>mid)
		return query(root*2+1, mid+1, e, i, j);
	else return query(root*2, s, mid, i, mid) + query(root*2+1, mid+1, e, mid+1, j);
}

void update(int root, int s, int e, int i, int j, LL val)
{
	if (s==i && e==j)
	{
		tree[root].sum += tree[root].n_child * val;
		tree[root].incr += val;
		return;
	}

	if (tree[root].incr > 0)
	{
		tree[root*2].incr += tree[root].incr;
		tree[root*2+1].incr += tree[root].incr;
		tree[root*2].sum += tree[root].incr * tree[root*2].n_child;
		tree[root*2+1].sum += tree[root].incr * tree[root*2+1].n_child;
		tree[root].incr = 0;
	}

	int mid = (s+e)>>1;
	if (j < mid+1)
		update(root*2, s, mid, i, j, val);
	else if (i > mid)
		update(root*2+1, mid+1, e, i, j, val);
	else
	{
		update(root*2, s, mid, i, mid, val);
		update(root*2+1, mid+1, e, mid+1, j, val);
	}
	tree[root].merge(tree[root*2],tree[root*2+1]);
	
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n,c,ch,p,q;
		LL v;
		get(n);
		get(c);
		build(1,0,n-1);

		F(i,c)
		{
			get(ch);
			get(p);
			get(q);
			p--;
			q--;
			if (ch)
				printf("%lld\n",query(1,0,n-1,p,q));
			else
			{
				getll(v);
				update(1,0,n-1,p,q,v);
			}
		}
	}
	return 0;
}