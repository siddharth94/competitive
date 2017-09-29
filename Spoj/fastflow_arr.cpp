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

struct edge
{
	int y;
	LL cap;
	LL flow;
};

struct path
{
	int source;
	int edge_ind;
};

vector <edge> adj[5005];
path parent[5005];

bool bfs(int s, int t)
{
	bool visited[5005] = {0};
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s].source = -1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i=0; i<adj[x].size(); i++)
		{
			if (visited[adj[x][i].y] || adj[x][i].cap <= adj[x][i].flow)
				continue;
			else
			{
				visited[adj[x][i].y] = true;
				q.push(adj[x][i].y);
				parent[adj[x][i].y].source = x;
				parent[adj[x][i].y].edge_ind = i;
				if (visited[t])
					break;
			}
		}
	}
	if (visited[t])
		return true;
	return false;
}

LL max_flow_algo(int s, int t)
{
	LL tot_flow = 0;
	while (bfs(s,t))
	{
		int y = t;
		LL min_cap = 1000009999;
		while(parent[y].source != -1)
		{
			min_cap = min(min_cap, adj[parent[y].source][parent[y].edge_ind].cap - adj[parent[y].source][parent[y].edge_ind].flow);
			y = parent[y].source;
		}
		y = t;
		while (parent[y].source != -1)
		{
			adj[parent[y].source][parent[y].edge_ind].flow += min_cap;
			y = parent[y].source;
		}
		tot_flow += min_cap;
	}
	return tot_flow;
}

int main()
{
	int n,m; 
	get(n);
	get(m);

	F(i,m)
	{
		int x,y;
		LL c;
		get(x);
		get(y);
		getll(c);
		edge tmp;
		tmp.cap = c;
		tmp.flow = 0;

		tmp.y = y;
		adj[x].pb(tmp);
		tmp.y = x;
		adj[y].pb(tmp);
	}

	printf("%lld\n", max_flow_algo(1,n));	

	return 0;
}