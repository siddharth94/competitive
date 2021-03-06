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

LL INF;

LL adj[105][105];

void floyd(int n)
{
	F(i,n)
		F(j,n)
			F(k,n)
				if (adj[j][i] + adj[i][k] < adj[j][k])
					adj[j][k] = adj[j][i] + adj[i][k];
}

int main()
{
	INF = 10000000000000LL;
	int n,e,t,m,x,y;
	LL cost;
	
	get(n);
	get(e);
	get(t);
	get(m);
	
	F(i,n)
		F(j,n)
			if (i==j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
	
	F(i,m)
	{
		get(x);
		get(y);
		x--;
		y--;
		getll(cost);
		adj[x][y] = adj[y][x] = cost;
	}

	floyd(n);
	e--;
	int count = 0;

	F(i,n)
	{
		if (adj[i][e] <= t)
			count++;
	}
	printf("%d\n",count);
	return 0;
}