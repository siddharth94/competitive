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

int arr[50005];

struct node
{
	int mmax, l_max, r_max, w_sum;
	node():mmax(-999999999),l_max(-999999999),r_max(-999999999),w_sum(0){}

	void init(int a)
	{
		mmax = a;
		l_max = a;
		r_max = a;
		w_sum = a;
	}

	void merge(node l, node r)
	{
		mmax = max(max(l.mmax, r.mmax), l.r_max + r.l_max);
		l_max = max(l.l_max, l.w_sum+r.l_max);
		r_max = max(r.r_max, r.w_sum + l.r_max);
		w_sum = l.w_sum + r.w_sum;
	}
}tree[200020];

void build(int root, int s, int e)
{
	if (s==e)
	{
		tree[root].init(arr[s]);
		return;
	}
	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);
	tree[root].merge(tree[root*2], tree[root*2+1]);
}

node query(int root, int s, int e, int qs, int qe)
{
	int mid = (s+e)>>1;

	if (s==qs && e==qe)
		return tree[root];
	else if (qs > mid)
		return query(root*2+1, mid+1, e, qs, qe);
	else if (qe <= mid)
		return query(root*2, s, mid, qs, qe);
	else if (qs <=mid && qe > mid)
	{
		node a,b,tmp;
		a = query(root*2, s,mid,qs,mid);
		b = query(root*2+1, mid+1,e,mid+1,qe);
		tmp.merge(a,b);
		return tmp;
	}
}

int main()
{
	int n;
	get(n);

	F(i,n)
		get(arr[i]);

	build(1,0,n-1);

	int m,ch,x,y;
	get(m);

	F(i,m)
	{
		get(x);
		get(y);
		printf("%d\n",query(1,0,n-1,x-1,y-1).mmax);
	}

	return 0;
}