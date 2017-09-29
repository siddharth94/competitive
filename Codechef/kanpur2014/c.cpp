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

LL a[100005];

struct node
{
	LL sum, m, i, j;
	bool inc, dec;

	void init(int i)
	{
		sum = a[i];
		m = a[i];
		i = i;
		j = i;
		inc = true;
		dec = true;
	}

	void merge(node l, node r)
	{
		i = l.i;
		j = r.j;
		sum = l.sum + r.sum;
		m = max(l.m, r.m);
		if (l.inc && r.inc && a[l.j] <= a[r.i])
			inc = true;
		else inc = false;
		if (r.dec && l.dec && a[l.j] >= a[r.i])
			dec = true;
		else dec = false;
	}
}tree[800005];

void build(int root, int s, int e)
{
	if (s==e)
	{
		tree[root].init();
		return;
	}
	int mid = (s+e)>>1;
	build(root*2,s,mid);
	build(root*2+1,mid+1,e);
	tree[root].merge(tree[root*2],tree[root*2+1]);
	return;
}

void update(int root, int s, int e, int i)
{
	if (s==e && s==i)
	{
		tree[root].init(i);
		return;
	}
	int mid = (s+e)>>1;
	if (i>mid)
		update(root*2+1,mid+1,e,i);
	else if (i<mid+1)
		update(root*2, s, mid, i);
	tree[root].merge(tree[root*2],tree[root*2+1]);
}

int maxdiff(int root, int s, int e, int x, int y)
{
	if (s==x && e==y)
		return tree[root].m;
	int mid = (s+e)>>1;
	if (x>mid)
		return maxdiff(root*2+1, mid+1, e, x, y);
	else if (y < mid+1)
		return maxdiff(root*2, s, mid, x, y);
	else
		return max(maxdiff(root*2, s, mid, x, mid), maxdiff(root*2+1, mid+1, e, mid+1, y));
}

LL sum(int root, int s, int e, int x, int y)
{
	if (s==x && e==y)
		return tree[root].sum;
	int mid = (s+e)>>1;
	if (x>mid)
		return sum(root*2+1, mid+1,e ,x,y);
	else if (y<mid+1)
		return sum(root*2, s,mid,x,y);
	else
		return sum(root*2,s,mid,x,mid)+sum(root*2+1,mid+1,e,mid+1,y);
}

int main()
{
	char c;
	int n,m;
	get(n);
	get(m);
	F(i,n)
		get(a[i]);
	build(1,0,n-1);
	int x,y;
	F(i,m)
	{
		scanf("%c %d %d", c,x,y);
		if (c=='U')
		{
			x--;
			a[x] = y;
			update(1,0,n-1,x);
		}
		if (c=='M')
		{
			x--;
			y--;
			cout << maxdiff(1,0,n-1,x,y) << endl;
		}
		if (c=='S')
		{
			x--;
			y--;
			cout << sum(1,0,n-1,x,y) << endl;
		}
	}
	return 0;
}