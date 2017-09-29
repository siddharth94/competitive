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

int a[10005];

struct node
{
	int sum, maxl, maxr, maxn;

	node():sum(0),maxl(0),maxr(0),maxn(0){}

	void init(int n)
	{
		sum = maxl = maxr = maxn = n;
	}

	void merge(node l, node r)
	{
		sum = l.sum + r.sum;
		maxl = (l.maxl < l.sum+r.maxl) ? l.sum+r.maxl : l.maxl;
		maxr = (r.maxr < r.sum+l.maxr) ? l.maxr+r.sum : r.maxr;
		maxn = max(l.maxr+r.maxl, max(	l.maxn, r.maxn));
	}

}stree[50005];

void build(int root, int s, int e)
{
	if (s==e)
	{
		stree[root].init(a[s]);
		return;
	}

	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);

	stree[root].merge(stree[root*2], stree[root*2+1]);
}

node query(int root, int s, int e, int qs, int qe)
{
	if (s==qs && e==qe)
		return stree[root];

	int mid = (s+e)>>1;

	if (qe <= mid)
		return query(root*2, s, mid, qs, qe);
	else if (qs > mid)
		return query(root*2+1, mid+1, e, qs, qe);
	else
	{
		node tmp;
		tmp.merge(query(root*2, s, mid, qs, mid), query(root*2+1, mid+1, e, mid+1, qe));
		return tmp;
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		F(i,n)
			get(a[i]);

		build(1,0,n-1);

		int m;
		get(m);
		F(i,m)
		{
			int x1,y1,x2,y2;
			get(x1);
			get(y1);
			get(x2);
			get(y2);
			x1--;y1--;x2--;y2--;

			if (y1 < x2)
			{
				node l = query(1,0,n-1,x1,y1);
				node r = query(1,0,n-1,x2,y2);
				node mid;
				if (y1+1 != x2)
					mid = query(1,0,n-1,y1+1,x2-1);
				printf("%d\n", l.maxr + mid.sum + r.maxl);
			}
			else
			{
				int l,r;
				
				node mid = query(1,0,n-1,x2,y1);
				
				if (x1 < x2)
					l = query(1,0,n-1,x1,x2-1).maxr + query(1,0,n-1,x2,y2).maxl;
				else l = query(1,0,n-1,x2,y2).maxl;

				if (y1 < y2)
					r = query(1,0,n-1,x1,y1).maxr + query(1,0,n-1,y1+1,y2).maxl;
				else r = query(1,0,n-1,x1,y1).maxr;
				
				printf("%d\n",max(mid.maxn, max(l,r)));
			}
		}

	}
	return 0;
}