#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(LL i=0;i<n;i++)
#define LL long long int
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void get(LL &x)
{
    register LL c = gc();
    x = 0;
    LL neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

struct s
{
	LL sum, val;
	s() {sum=val=0;}
}a[300000];

void update(LL ss, LL se, LL qs, LL qe, LL x, LL val)
{
	if(ss==qs && se==qe)
	{
		a[x].val+=val;
		return;
	}
	LL m=(ss+se)/2;
	if(qe<=m)
			update(ss,m,qs,qe,2*x, val);
	else if(qs>m)
		update(m+1,se,qs,qe,2*x+1,val);
	else
	{
		update(ss,m,qs,m,2*x,val);
		update(m+1,se,m+1,qe,2*x+1,val);
	}
	a[x].sum=a[2*x].sum+a[2*x+1].sum + (m-ss+1)*a[2*x].val + (se-m)*a[2*x+1].val;
}

LL query(LL ss, LL se, LL qs, LL qe, LL x)
{
	if(ss==qs && se==qe)
		return (qe-qs+1)*a[x].val+a[x].sum;;
	LL m=(ss+se)>>1;
	if(qe<=m)
		return query(ss,m,qs,qe,2*x) + (qe-qs+1)*a[x].val;
	else if(qs>m)
		return query(m+1,se,qs,qe,2*x+1) + (qe-qs+1)*a[x].val;
	else
		return query(ss,m,qs,m,2*x) + query(m+1,se,m+1,qe,2*x+1) + (qe-qs+1)*a[x].val;
}

int main()
{
	LL T, n, p, q, x, c, v;
	get(T);
	while (T--)
	{
			for(LL i=0;i<300000;i++)
			 	a[x].sum=a[x].val=0;
			get(n);
			get(c); 
			F(i,c)
			{
				get(x);
				get(p);
				get(q);
				if(x==0)
				{
					get(v);
					update(1,n,p,q,1,v);
				}
				else
					printf("%lld\n", query(1,n,p,q,1));
			}

	}
	return 0;
}