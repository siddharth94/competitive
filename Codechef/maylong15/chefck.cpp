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

LL mod = 1000000007;
LL arr[10000005];
LL stree[40005005];

void build(LL root, LL s, LL e)
{
	if (s==e)
	{
		stree[root] = arr[s];
		return;
	}
	LL mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);
	stree[root] = min(stree[root*2] , stree[root*2+1]);
}

LL query(LL root, LL s, LL e, LL i, LL j)
{
	if (s==i && e==j)
		return stree[root];
	LL mid = (s+e)>>1;
	if (i > mid)
		return query(root*2+1, mid+1, e, i, j);
	else if (j < mid+1)
		return query(root*2, s, mid, i, j);
	else
		return min( query(root*2, s, mid, i, mid), query(root*2+1, mid+1, e, mid+1, j));
}

int main()
{
	LL n,k,q;
	LL a,b,c,d,e,f,r1,s,t,m;
	LL l1, la, lc, lm, d1, da, dc, dm;
	LL l,r;

	getll(n);
	getll(k);
	getll(q);
	getll(a);
	getll(b);
	getll(c);
	getll(d);
	getll(e);
	getll(f);
	getll(r1);
	getll(s);
	getll(t);
	getll(m);
	getll(arr[1]);
	getll(l1);
	getll(la);
	getll(lc);
	getll(lm);
	getll(d1);
	getll(da);
	getll(dc);
	getll(dm);

	LL tp = t%s;
	LL ind;

	RE(i,2,n)
	{
		tp = (tp*t)%s;
		if (tp <= r1)
			arr[i] = (a * ((arr[i-1]*arr[i-1])%m) + b*arr[i-1] + c) % m;
		else
			arr[i] = (d * ((arr[i-1]*arr[i-1])%m) + e*arr[i-1] + f) % m;

		// if (arr[i] == arr[1])
		// {
		// 	ind = i;
		// 	break;
		// }
	}

	build(1,1,n);
	LL qsum = 0;
	LL qprod = 1;

	RE(i,1,q)
	{
		l1 = (la * l1 + lc) % lm;
		d1 = (da * d1 + dc) % dm; 
		l = l1 + 1;
		r = min(l + k - 1 + d1, n);
		LL minim = query(1,1,n,l,r);
		qsum += minim;
		qprod *= minim;
		qprod %= mod;
	}

	printf("%lld %lld\n", qsum, qprod);

	return 0;
}