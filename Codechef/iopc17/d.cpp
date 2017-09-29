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

vector <int> table[12505];
int sum[12505];
LL mod = 1000000007ll;
int stree[4*12505];

void calc()
{
	table[0].pb(1ll);

	for (int i=1; i<12501; i++)
	{
		table[i].resize(i+1);
	}


	for (int n=1; n<12501; n++)
	{
		table[n][n] = 1;
		sum[n] = 0ll;
		for (int r=1; r<=n; r++)
		{
			sum[n] = ((LL)sum[n]+(LL)table[n][r]) % mod;
			
			if (n+r < 12501)
				table[n+r][r] = sum[n];
		}
	
		for (int k=n*2; k<12501; k++)
		{
			table[k][k-n] = sum[n];
		}
	}
}

void build_tree(int root, int ss, int se)
{
	if (ss==se)
	{
		stree[root] = sum[ss];
		return;
	}

	int mid = (ss+se)>>1;
	build_tree(root*2, ss, mid);
	build_tree(root*2+1, mid+1, se);

	stree[root] = ((LL)stree[root*2]*(LL)stree[root*2+1]) % mod;
}

int query(int root, int ss, int se, int qs, int qe)
{
	if (ss==qs && se==qe)
	{
		return stree[root];
	}

	int mid = (ss+se)>>1;
	if (qs > mid) return query(root*2+1, mid+1, se, qs, qe);
	else if (qe <= mid) return query(root*2, ss, mid, qs, qe);
	else
	{
		return (((LL)query(root*2, ss, mid, qs, mid) * (LL)query(root*2+1, mid+1, se, mid+1, qe) ) % mod);
	}
}

int main()
{
	calc();
	memset(stree, 0, sizeof stree);

	build_tree(1, 1, 12500);
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;

		get(n);
		get(m);

		int ans = query(1,1,12500,m,m+n-1);
		while (ans < 0)
		{
			ans += mod;
		}

		printf("%d\n", ans);
	}
	return 0;
}