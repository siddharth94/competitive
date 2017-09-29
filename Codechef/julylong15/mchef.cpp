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

LL rating[100005];
int cost[100005];
int stree[405005];
LL dp[100005][505];

void update(int root, int s, int e, int i, int j, int x)
{
	if (s==i && e==j)
	{
		stree[root] = min(stree[root],x);
		return;
	}
	int mid = (s+e)>>1;
	if (j <= mid)
		update(root*2, s, mid, i, j, x);
	else if (i > mid)
		update(root*2+1, mid+1, e, i, j, x);
	else
	{
		update(root*2, s, mid, i, mid, x);
		update(root*2+1, mid+1, e, mid+1, j, x);
	}
}

void gencost(int root, int s, int e, int mini)
{
	if (s==e)
	{
		cost[s] = min(stree[root], mini);
		return;
	}
	int mid = (s+e)>>1;
	mini = min(mini,stree[root]);
	gencost(root*2, s, mid, mini);
	gencost(root*2+1, mid+1, e, mini);
}

int main()
{
	int inf = 9000;
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		F(i,405005) stree[i] = inf;
		int n,k,m;
		get(n);
		get(k);
		get(m);
		LL sum = 0;
		F(i,n)
		{
			getll(rating[i]);
			sum += rating[i];
		}
		F(i,m)
		{
			int l,r,c;
			get(l);
			get(r);
			get(c);
			l--, r--;
			update(1,0,n,l,r,c);
		}
		gencost(1,0,n,inf);
		FE(i,n)
		{
			FE(j,k)
			{
				if (i==0 || j==0)
				{
					dp[i][j] = 0;
					continue;
				}

				if (cost[i-1] > j)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = min(dp[i-1][j], rating[i-1]+dp[i-1][j-cost[i-1]]); 
			}
		}
		printf("%lld\n", sum-dp[n][k]);
	}
	return 0;
}