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

int mark[105];
vector<int> adj[105];
queue <int> q;
int l[105];

int bfs()
{
	int level = 0;
	while (!q.empty())
	{
		int i = q.front();
		level = l[q.front()];
		int sz = adj[i].size();
		mark[i] = -1;

		F(j,sz)
		{
			if (mark[adj[i][j]] == -1)
				continue;
			else
			{
				l[adj[i][j]] = level + 1;
				q.push(adj[i][j]);
				mark[adj[i][j]] = -1;
			}
		}
		q.pop();
	}
	return level+1;
}

int d[105];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;
		get(n);
		get(m);
		F(i,m)
		{
			int x,y;
			get(x);
			get(y);
			x--, y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		F(i,n)
		{
			l[i] = 0;
			q.push(i);
			d[i] = bfs();
			memset(l,0, sizeof(l));
			memset(mark, 0, sizeof(mark));
		}

		bool solved = false;
		for (int i=1; i<n; i++)
		{
			if (d[i] != d[i-1])
			{
				printf("-1 -1\n");
				solved = true;
			}
		}

		if (!solved)
		{
			printf("0 0\n");
		}

		memset(d, 0, sizeof(d));
	}	
	return 0;
}