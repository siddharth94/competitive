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

struct node
{
	int start, end;
	int depth;
};

int t;
vector <int> adj[100005];
node tree[100005];
vector <int> dfn_no;
int stree[800005];
int query[1000005];
vector <int> a;
vector <int> b;
vector <int> c;
bool visited[100005];

void dfs(int node, int level)
{
	tree[node].start = t;
	tree[node].depth = level;
	t++;
	dfn_no.pb(node);

	F(i, adj[node].size())
	{
		if (visited[adj[node][i]])
			continue;
		visited[adj[node][i]] = true;
		dfs(adj[node][i], level+1);
		visited[adj[node][i]] = false;
		dfn_no.pb(node);
		tree[node].end = t;
		t++;
	}

	if (adj[node].size() == 1 && node != 0)
		tree[node].end = t-1;
}

void build(int root, int s, int e)
{
	if (s==e)
	{
		stree[root] = tree[s].depth;
		return;
	}
	int mid = (s+e)>>1;
	build(root*2, s, mid);
	build(root*2+1, mid+1, e);	
stree[root] = min(stree[root*2], stree[root*2+1]);
}

int lca(int root, int s, int e, int qs, int qe)
{
	if (s==qs && e==qe)
		return stree[root];
	int mid = (s+e)>>1;
	if (qe <= mid)
		return lca(root*2, s, mid, qs, qe);
	else if (qs > mid)
		return lca(root*2+1, mid+1, e, qs, qe);
	else
		return min(lca(root*2, s, mid, qs, mid), lca(root*2+1, mid+1, e, mid+1, qe));
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		F(i,n-1)
		{
			int x,y;
			get(x);
			get(y);
			x--, y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		t = 0;
		dfn_no.clear();
		memset(visited, 0, sizeof(visited));
		visited[0] = true;
		dfs(0,0);
		build(1,0,dfn_no.size()-1);
		int q;
		get(q);
		F(i,q)
		{
			a.clear();
			b.clear();
			c.clear();
			int k;
			get(k);

			get(query[0]);
			query[0]--;
			
			int a_min_depth = query[0];
			int a_max_depth = query[0]; 
			int b_min_depth = 0;
			int b_max_depth = 0; 
			
			R(j,1,k)
			{
				get(query[j]);
				query[j]--;
				if (tree[a_min_depth].depth > tree[query[j]].depth)
					a_min_depth = query[j];
				if (tree[a_max_depth].depth < tree[query[j]].depth)
					a_max_depth = query[j];
			}
			b_min_depth = a_max_depth;
			F(j,k)
			{
				if (tree[query[j]].start <= tree[a_max_depth].start && tree[query[j]].end >= tree[a_max_depth].end)
					a.pb(query[j]);
				else
				{ 
					b.pb(query[j]);
					if (tree[b_min_depth].depth > tree[query[j]].depth)
						b_min_depth = query[j];
					if (tree[b_max_depth].depth < tree[query[j]].depth)
						b_max_depth = query[j];
				}
			}
			if (b.size() == 0)
			{
				printf("Yes\n");
				continue;
			}
			F(j,b.size())
			{
				if (!(tree[b[j]].start <= tree[b_max_depth].start && tree[b[j]].end >= tree[b_max_depth].end))
					c.pb(b[j]);
			}
			if (c.size() > 0)
			{
				printf("No\n");
				continue;
			}
			if (tree[a_max_depth].start < tree[b_max_depth].start)
			{
				if (lca(1, 0, dfn_no.size(), tree[a_max_depth].end, tree[b_max_depth].start) <= tree[a_min_depth].depth)
					printf("Yes\n");
				else
					printf("No\n");
			}
			else
			{
				if (lca(1, 0, dfn_no.size(), tree[b_max_depth].end, tree[a_max_depth].start) <= tree[a_min_depth].depth)
					printf("Yes\n");
				else
					printf("No\n");	
			}
		}
		F(i,n)
			adj[i].clear();
	}
	return 0;
}