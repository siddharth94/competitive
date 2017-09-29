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

char num[100005];

struct node;

LL cans(node l, node r);

struct node
{
	LL total, ans;
	LL pre[3];
	LL suf[3];

	void init(int tmp)
	{
		memset(pre, 0, sizeof(pre));
		memset(suf, 0, sizeof(suf));
		total = (LL)tmp;
		ans = (tmp%3==0)?1:0;
		pre[tmp%3] = 1;
		suf[tmp%3] = 1;
	}

	void merge(node l, node r)
	{
		memset(pre, 0, sizeof(pre));
		memset(suf, 0, sizeof(suf));
		total = l.total + r.total;
		ans = cans(l,r);
		F(i,3)
		{
			pre[i] += l.pre[i];
			suf[i] += r.suf[i];
			pre[(l.total + i)%3] += r.pre[i];
			suf[(r.total + i)%3] += l.suf[i];
		}
	}

}stree[400005];

LL cans(node l, node r)
{
	LL ans = l.ans + r.ans;
	F(i,3)
		F(j,3)
			if ((i+j)%3==0)
				ans += l.suf[i] * r.pre[j];
	return ans;
}

void build(int root, int s, int e)
{
	if (s == e)
	{
		stree[root].init(num[s]-'0');
		return;
	}

	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);
	stree[root].merge(stree[root*2], stree[root*2+1]);
}

void update(int root, int s, int e, int idx, LL val)
{
	if (s==e)
	{
		stree[root].init(val);
		return;
	}

	int mid = (s+e)>>1;
	if (idx <= mid)
		update(root*2, s, mid, idx, val);
	else if (idx > mid)
		update(root*2+1, mid+1, e, idx, val);

	stree[root].merge(stree[root*2], stree[root*2+1]);
}

node query(int root, int s, int e, int qs, int qe)
{
	if (s == qs && e == qe)
		return stree[root];

	node tmp;
	int mid = (s+e)>>1;

	if (qe <= mid)
		tmp = query(root*2, s, mid, qs, qe);
	else if (qs > mid)
		tmp = query(root*2+1, mid+1, e, qs, qe);
	else
	{
		node tmp1, tmp2;
		tmp1 = query(root*2, s, mid, qs, mid);
		tmp2 = query(root*2+1, mid+1, e, mid+1, qe);
		tmp.merge(tmp1, tmp2);
	}
	return tmp;
}

int main()
{
	int n,m;
	get(n);
	get(m);

	scanf("%s",num);

	build(1,0,n-1);

	F(i,m)
	{
		int type,x,y;
		get(type);
		get(x);
		get(y);
		x--;
		if (type == 1)
			update(1,0,n-1,x,y);
		else
		{
			y--;
			printf("%lld\n",query(1,0,n-1,x,y).ans);
		}
	}
	return 0;
}