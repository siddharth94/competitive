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

struct node
{
	int lchild, rchild;
	pii in;
	int maxrval;

	node():lchild(-1),rchild(-1)
	{
		in = mp(0,0);
	}

	void init(pii ival)
	{
		in = ival;
		maxrval = in.sd;
	}

}tree[100005];

LL arr[100005];
LL bitarr[100005];
pii fn[100005];
LL fnsum[100005];
LL bitfnsum[100005];

void updatearr(LL val, int idx, int n)
{
	for (int i=idx; i<n; i+=(i&(-i)))
	{
		bitarr[i] += val;
		if (i == 0)
			break;
	}
}

LL queryarr(int idx)
{
	LL ans = 0;
	for (int i=idx; i>=0; i-=(i&(-i)))
	{
		ans += bitarr[i];
		if (i == 0)
			break;
	}
	return ans;
}

void updatefn(LL val, int idx, int n)
{
	for (int i=idx; i<n; i+=(i&(-i)))
	{
		bitfnsum[i] += val;
		if (i == 0)
			break;
	}
}

LL queryfn(int idx)
{
	LL ans = 0;
	for (int i=idx; i>=0; i-=(i&(-i)))
	{
		ans += bitfnsum[i];
		if (i==0)
			break;
	}
	return ans;
}

void insert(int root, pii ival, int idx)
{
	if (ival.ft <= tree[root].in.ft)
	{
		if (tree[root].lchild == -1)
		{
			tree[root].lchild = idx;
			tree[idx].init(ival);
		}
		else insert(tree[root].lchild, ival, idx);
	}
	else if (ival.ft > tree[root].in.ft)
	{
		if (tree[root].rchild == -1)
		{
			tree[root].rchild = idx;
			tree[idx].init(ival);
		}
		else insert(tree[root].rchild, ival, idx);
	}
	tree[root].maxrval = max(tree[root].maxrval, tree[tree[root].rchild].maxrval);
	tree[root].maxrval = max(tree[root].maxrval, tree[tree[root].lchild].maxrval);
}

void updatetree(int root, int val, int x, int n)
{
	if (tree[root].in.ft <= x && tree[root].in.sd >= x)
		updatefn (val, root, n);

	if (tree[tree[root].lchild].maxrval >= x)
		updatetree(tree[root].lchild, val, x, n);
	if (tree[tree[root].rchild].maxrval >= x)
		updatetree(tree[root].rchild, val, x, n);
}

int main()
{
	int n,x,y,type;
	get(n);

	F(i,n)
	{
		getll(arr[i]);
		updatearr(arr[i],i,n);
	}

	LL l,r,temp;

	F(i,n)
	{
		get(fn[i].ft);
		fn[i].ft--;
		get(fn[i].sd);
		fn[i].sd--;
	}

	tree[0].in = fn[0];
	tree[0].maxrval = fn[0].sd;

	R(i,1,n)
		insert(0,fn[i],i);

	F(i,n)
	{
		l = queryarr(fn[i].ft-1);
		r = queryarr(fn[i].sd);
		fnsum[i] = r-l;
		updatefn(r-l, i, n);
	}

	int q;
	get(q);

	F(i,q)
	{
		get(type);
		get(x);
		get(y);
		
		if (type == 1)
		{
			x--;
			temp = arr[x];
			arr[x] = y;
			updatetree(0, y-temp, x, n);
			// F(j,n)
			// {
			// 	if (fn[j].ft <= x && fn[j].sd >= x)
			// 		updatefn (y-temp, j, n);
			// }
		}
		else
		{
			x--;
			y--;
			l = queryfn(x-1);
			r = queryfn(y);
			printf("%lld\n", r-l);
		}
	}

	return 0;
}