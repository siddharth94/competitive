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

char str[30005];

struct node
{
	int open,close;
	
	node():close(0),open(0){}

	void init(char s)
	{
		if (s=='(')
			open = 1, close = 0;
		else
			open = 0, close = 1;
	}

	void merge(node l, node r)
	{
		int mi = min(l.open,r.close);
		open = l.open + r.open - mi;
		close = l.close + r.close - mi;
	}

}tree[120001];

void build(int root, int s, int e)
{
	if (s==e)
	{
		tree[root].init(str[s]);
		return;
	}
	int mid = (s+e)>>1;
	build(2*root, s,mid);
	build(2*root + 1, mid+1, e);
	tree[root].merge(tree[root*2], tree[root*2+1]);
}

void update(int root, int s, int e, int val)
{
	if (s==e)
	{
		if (str[s] == '(')
			str[s] = ')';
		else str[s] = '(';

		tree[root].init(str[s]);
		return;
	}
	int mid = (s+e)>>1;
	if (val>=s && val<=mid)
		update(root*2, s,mid,val);
	else if (val>mid && val<=e)
		update(root*2+1, mid+1, e,val);
	tree[root].merge(tree[root*2],tree[root*2+1]);
}

int main()
{
	int T = 10;
	while (T--)
	{
		printf("Test %d:\n",10-T);
		int n;
		get(n);

		scanf("%s",str);
		build(1,0,n-1);

		int m;
		get(m);

		int k;
		F(i,m)
		{
			get(k);
			if (k)
				update(1,0,n-1,k-1);
			else
			{
				if (tree[1].close == 0 && tree[1].open == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}