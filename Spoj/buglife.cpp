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

vector <int> adj[2005];
bool visited[2005];
int color[2005];

bool dfs(int bug, int col)
{
	visited[bug] = true;
	color[bug] = col;
	int n = adj[bug].size();
	F(i,n)
	{
		if (color[adj[bug][i]] == col)
			return false;
		if (!visited[adj[bug][i]])
			if (!dfs(adj[bug][i], !col))
				return false;
	}
	return true;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		printf("Scenario #%d:\n",__rep);
		int bugs,n,x,y;
		get(bugs);
		get(n);	
		int tmp;
		F(i,n)
		{
			get(x);
			get(y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		memset(color, -1, sizeof(color));
		memset(visited, false, sizeof(visited));
		bool tr = true;
		RE(i,1,bugs)
		{
			if (!visited[i])
				if (!dfs(i,0))
					tr = false;
		}
		if (tr)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		RE(i,1,bugs)
			adj[i].clear();
	}
	return 0;
}