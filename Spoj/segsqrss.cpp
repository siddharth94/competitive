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

LL a[100005];

struct node
{
	bool changed;
	int n_children;
	LL sum;
	LL sum_sq;
	LL new_val;
	LL incr;

	void init(LL val)
	{
		changed = false;
		sum = val;
		sum_sq = val*val;
		n_children = 1;
		new_val = 0;
		incr = 0;
	}

	void merge(node l, node r)
	{
		n_children = l.n_children + r.n_children;
		sum = l.sum + r.sum;
		sum_sq = l.sum_sq + r.sum_sq;
	}

	void updatezero(int x)
	{
		changed = true;
		sum = n_children*x;
		sum_sq = n_children*x*x;
		new_val = x;
	}

	void updateone(int x)
	{
		changed = true;
		sum_sq = sum_sq + 2*x*sum + n_children*x*x;
		sum += n_children*x;
		incr += x;
	}

	void split(node l, node r)
	{
		changed = false;
		l.updatezero(new_val);
		l.updateone(incr);
		r.updatezero(new_val);
		r.updateone(incr); 
		new_val = 0;
		incr = 0;
	}
}tree[400005];

void build(int root, int s, int e)
{
	if (s==e)
	{
		tree[root].init(a[s]);
		return;
	}
	int mid = (s+e)>>1;
	build(root*2, s,mid);
	build(root*2+1, mid+1,e);
	tree[root].merge(tree[root*2],tree[root*2+1]);
}

void updatezero(int root, int s, int e, int i, int j, LL x)
{
	if (tree[root].changed)
		tree[root].split(tree[root*2], tree[root*2+1]);

	if (s==i && e==j)
	{
		tree[root].updatezero(x);
		return;
	}
	else
	{
		int mid = (s+e)>>1;
		if (i>mid)
			updatezero(root*2+1, mid+1, e, i, j, x);
		else if (j<=mid)
			updatezero(root*2, s, mid, i, j, x);
		else
		{
			updatezero(root*2, s, mid, i, mid, x);
			updatezero(root*2, mid+1, e, mid+1, j, x);
		}
	} 
	tree[root].merge(tree[root*2], tree[root*2+1]);
}

void updateone(int root, int s, int e, int i, int j, LL x)
{
	if (tree[root].changed)
		tree[root].split(tree[root*2], tree[root*2+1]);

	if (s==i && e==j)
	{
		tree[root].updateone(x);
		return;
	}
	else
	{
		int mid = (s+e)>>1;
		if (i>mid)
			updateone(root*2+1, mid+1, e, i, j, x);
		else if (j<=mid)
			updateone(root*2, s, mid, i, j, x);
		else
		{
			updateone(root*2, s, mid, i, mid, x);
			updateone(root*2+1, mid+1, e, mid+1, j, x);
		}
	}
	tree[root].merge(tree[root*2],tree[root*2+1]);
}

LL query(int root, int s, int e, int i, int j)
{
	if (tree[root].changed)
		tree[root].split(tree[root*2], tree[root*2+1]);

	if(s==i && e==j)
		return tree[root].sum_sq;
	else
	{
		int mid = (s+e)>>1;
		if (i>mid)
			return query(root*2+1, mid+1, e, i, j);
		else if (j<=mid)
			return query(root*2, s, mid, i, j);
		else
			return query(root*2, s, mid, i, mid) + query(root*2+1, mid+1, e, mid+1, j);
	}
}

int main()
{
	int T;
	get(T);
	F(Z,T)
	{
		printf("Case %d:\n", Z+1);
		int n,q,ch,x,y;
		LL z;
		get(n);	
		get(q);
		
		F(i,n)
			getll(a[i]);

		build(1,0,n-1);
		F(i,q)
		{
			get(ch);
			get(x);
			get(y);
			x--;
			y--;
			if (ch==0)
			{
				getll(z);
				updatezero(1,0,n-1,x,y,z);
			}
			else if (ch==1)
			{
				getll(z);
				updateone(1,0,n-1,x,y,z);
			}
			else
				printf("%lld\n", query(1,0,n-1,x,y));
		}
	}
	return 0;
}