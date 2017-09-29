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

int gcd(int a, int b)
{
	if (a>b)
		swap(a,b);
	if (b%a==0 || a==1)
		return a;
	return gcd(b%a,a);
}

void build(int root, int s, int e)
{
	if (s==e)
	{
		stree[root] = a[s];
		return;
	}
	
	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);

	stree[root] = gcd(stree[root*2], stree[root*2+1]);
}

int query(int root, int s, int e, int qs, int qe)
{
	if (s == qs && e == qe)
		return stree[root];
	int mid = (s+e)>>1;
	if (qs > mid)
		return query(root*2+1, mid+1, e, qs, qe);
	else if (qe <= mid)
		return query(root*2, s, mid, qs, qe);
	else
		return gcd(query(root*2, s, mid, qs, mid), query(root*2+1, mid+1, e, mid+1, qe));
}

int main()
{
	// gcd(2,9);
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,q;
		get(n);
		get(q);
		
		F(i,n)
			get(a[i]);
		build(1,0,n-1);

		F(i,q)
		{
			int l,r;
			get(l);
			get(r);
			l-=2;
			int lg = -1, rg = -1;
			if (l>=0)
				lg = query(1,0,n-1,0,l);
			if (r < n)
				rg = query(1,0,n-1,r,n-1);
			if (lg!=-1 && rg!=-1)
				printf("%d\n",gcd(lg,rg) );
			else if (lg==-1)
				printf("%d\n",rg);
			else 
				printf("%d\n",lg);

		}
	}
	return 0;
}