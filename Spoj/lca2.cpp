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

vector <int> adj[1005];
int parent[1005];
int level[1005];
queue <int> q;
int lca[1005][12];

void lca_gen()
{
	memset(lca, -1, sizeof(lca));
	level[q.front()] = 0;
	while (!q.empty())
	{
		int n = adj[q.front()].size();
		F(i,n)
			q.push(adj[q.front()][i]);
		for (int j=0; 1<<j <= level[q.front()]; j++)
			j == 0 ? lca[q.front()][j] = parent[q.front()] : lca[q.front()][j] = lca[lca[q.front()][j-1]][j-1];
		q.pop();
		if (!q.empty())
			level[q.front()] = level[parent[q.front()]] + 1;
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		printf("Case %d:\n",__rep);
		int n;
		get(n);
		int root = (n*(n+1))/2;
		F(i,n)
		{
			int m;
			get(m);
			F(j,m)
			{
				int a;
				get(a);
				root -= a;
				a--;
				parent[a] = i;
				level[a] = -1;
				adj[i].pb(a);
			}
		}
		root--;
		q.push(root);
		
		lca_gen();
		
		// F(i,n)
		// {
		// 	int j = 0;
		// 	while (lca[i][j] != -1)
		// 		printf("%d ", lca[i][j++]);
		// 	printf("\n");
		// }

		int q;
		get(q);
		while (q--)
		{
			int v,w;
			get(v);
			get(w);
			v--;
			w--;

			if (level[v] < level[w])
				swap(v,w);

			int lg = log2(level[v]);

			while (level[v] != level[w])
			{
				if (level[lca[v][lg]] >= level[w])
					v = lca[v][lg];
				lg--;
			}

			if (v == w)
			{
				printf("%d\n",v+1);
				continue;
			}

			lg = log2(v);

			FRE(i,lg)
			{
				if (lca[v][i] != lca[w][i])
				{
					v = lca[v][i];
					w = lca[w][i];
				}
			}

			printf("%d\n",parent[v] + 1);
		}
		F(i,1005)
			adj[i].clear();
	}
	return 0;
}