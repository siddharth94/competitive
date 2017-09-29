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

int mat[105][105];
queue < pii > q;
int cost[105][105];
int m,n;
int t;

void bfs()
{
	while (!q.empty())
	{
		int x,y;
		x = q.front().ft;
		y = q.front().sd;
		if (x>=0 && cost[x-1][y] > cost[x][y] + mat[x][y])
		{
			cost[x-1][y] = cost[x][y] + mat[x][y];
			if (cost[x-1][y] <= t)
				q.push(mp(x-1,y));
		}
		if (x<m-1 && cost[x+1][y] > cost[x][y] + mat[x][y])
		{
			cost[x+1][y] = cost[x][y] + mat[x][y];
			if (cost[x+1][y] <= t)
				q.push(mp(x+1,y));
		}
		if (y<n-1 && cost[x][y+1] > cost[x][y] + mat[x][y])
		{
			cost[x][y+1] = cost[x][y] + mat[x][y];
			if (cost[x][y+1] <= t)
				q.push(mp(x,y+1));
		}
		if (y>=0 && cost[x][y-1] > cost[x][y] + mat[x][y])
		{
			cost[x][y-1] = cost[x][y] + mat[x][y];
			if (cost[x][y-1] <= t)
				q.push(mp(x,y-1));
		}
		q.pop();
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		get(m);
		get(n);
		F(i,m)
			F(j,n)
			{
				cost[i][j] = 999999999;
				get(mat[i][j]);
			}
		int x,y;
		get(x);
		get(y);
		get(t);
		cost[0][0] = 0;
		q.push(mp(0,0));
		bfs();
		if (t >= cost[x-1][y-1] + mat[x-1][y-1])
			printf("YES\n%d\n", t-(cost[x-1][y-1] + mat[x-1][y-1]));
		else
			printf("NO\n");
	}
	return 0;
}