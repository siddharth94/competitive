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

struct node
{
	LL green,red;
	bool flipped;
	node():green(1),red(0),flipped(false){}

	void flip()
	{
		swap(green,red);
		flipped = !flipped;
	}

	void merge(node l, node r)
	{
		green = l.green + r.green;
		red = l.red + r.red;
	}

	// void split(node* l, node *r)
	// {
	// 	*l->flip();
	// 	*r->flip();
	// 	flipped = false;
	// }
}xtree[500005],ytree[500005],ztree[500005];

void build(LL root, LL s, LL e, LL tree)
{
	if (s==e)
		return;
	
	LL mid = (s+e)>>1;
	build(root*2,s,mid,tree);
	build(root*2+1,mid+1,e,tree);

	switch(tree)
	{
		case 0 : xtree[root].merge(xtree[root*2],xtree[root*2+1]); break;
		case 1 : ytree[root].merge(ytree[root*2],ytree[root*2+1]); break;
		case 2 : ztree[root].merge(ztree[root*2],ztree[root*2+1]); break;
	}
}

void update(LL root, LL s, LL e, LL i, LL j, LL tree)
{
	node *ptree;
	
	switch(tree)
	{
		case 0 : ptree = xtree; break;
		case 1 : ptree = ytree; break;
		case 2 : ptree = ztree; break;
	}

	if (s==i && e==j)
	{
		ptree[root].flip();
		return;
	}

	LL mid = (s+e)>>1;

	if (ptree[root].flipped)
	{
		// ptree[root].split(&ptree[root*2],&ptree[root*2+1]);
		ptree[root*2].flip();
		ptree[root*2+1].flip();
		ptree[root].flipped = false;
	}

	if (i > mid)
		update(root*2+1, mid+1,e,i,j,tree);
	else if (j <= mid)
		update(root*2, s,mid,i,j,tree);
	else
	{
		update(root*2, s,mid,i,mid,tree);
		update(root*2+1, mid+1,e,mid+1,j,tree);
	}

	ptree[root].merge(ptree[root*2], ptree[root*2+1]);
}

LL query(LL root, LL s, LL e, LL i, LL j, LL tree)
{
	node *ptree;

	switch(tree)
	{
		case 0: ptree = xtree; break;
		case 1: ptree = ytree; break;
		case 2: ptree = ztree; break;
	}

	if (s==i && e==j)
		return ptree[root].red;

	if (ptree[root].flipped)
	{
		// ptree[root].split(&ptree[root*2],&ptree[root*2+1]);
		ptree[root*2].flip();
		ptree[root*2+1].flip();
		ptree[root].flipped = false;
	}

	LL mid = (s+e)>>1;

	if (i>mid)
		return query(root*2+1, mid+1,e,i,j,tree);
	else if (j<=mid)
		return query(root*2, s,mid,i,j,tree);
	else
		return query(root*2, s,mid,i,mid,tree) + query(root*2+1, mid+1,e,mid+1,j,tree);
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		LL x,y,z,q,qr,x1,y1,z1,x2,y2,z2,xone,yone,zone,i,j;
		getll(x);
		getll(y);
		getll(z);
		getll(q);

		build(1,0,x-1,0);
		build(1,0,y-1,1);
		build(1,0,z-1,2);

		while(q--)
		{
			getll(qr);

			switch(qr)
			{
				case 0:
					getll(i);
					getll(j);
					update(1,0,x-1,i,j,qr);
					break;
				case 1:
					getll(i);
					getll(j);
					update(1,0,y-1,i,j,qr);
					break;
				case 2:
					getll(i);
					getll(j);
					update(1,0,z-1,i,j,qr);
					break;
				case 3:
					getll(x1);
					getll(y1);
					getll(z1);
					getll(x2);
					getll(y2);
					getll(z2);
					xone = query(1,0,x-1,x1,x2,0);
					yone = query(1,0,y-1,y1,y2,1);
					zone = query(1,0,z-1,z1,z2,2);
					printf("%lld\n", ((xone*(y2-y1+1-yone)*(z2-z1+1-zone)) + ((x2-x1+1-xone)*yone*(z2-z1+1-zone)) + ((x2-x1+1-xone)*(y2-y1+1-yone)*zone) + (xone*yone*zone)));
					break;
			}
		}
	}
	return 0;
}