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

vector <int> adj[5005];
vector <int> rev_adj[5005];
stack <int> st;
bool visited[5005];
bool loc_visited[5005];
vector <int> scc;
vector <int> bot_list;

void dfs(int root)
{
	F(i, adj[root].size())
	{
		if (!visited[adj[root][i]])
		{
			visited[adj[root][i]] = true;
			dfs(adj[root][i]);
		}
	}
	st.push(root);
}

void dfs2(int root)
{
	F(i, rev_adj[root].size())
	{
		if (!visited[rev_adj[root][i]])
		{
			visited[rev_adj[root][i]] = true;
			loc_visited[rev_adj[root][i]] = true;
			dfs2(rev_adj[root][i]);
		}
	}
	scc.pb(root);
}

int main()
{
	while(1)
	{
		memset(visited, 0, sizeof(visited));
		bot_list.clear();
		int v,e;
		get(v);
		if (v==0)
			break;
		get(e);
		F(i,e)
		{
			int x,y;
			get(x);
			get(y);
			adj[x].pb(y);
			rev_adj[y].pb(x);
		}
		RE(i,1,v)
		{
			if (!visited[i])
			{
				visited[i] = true;
				dfs(i);
			}
		}
		memset(visited, 0, sizeof(visited));
		while (!st.empty())
		{
			if (visited[st.top()])
			{
				st.pop();
				continue;
			}
			
			scc.clear();
			memset(loc_visited, 0, sizeof(loc_visited));
			loc_visited[st.top()] = true;
			visited[st.top()] = true;
			dfs2(st.top());

			bool is_bot = true;
			F(i, scc.size())
			{
				F(j, adj[scc[i]].size())
				{
					if (!loc_visited[adj[scc[i]][j]])
					{
						is_bot = false;
						break;
					}
				}
				if (!is_bot)
					break;
			}
			if (is_bot)
			{
				F(i,scc.size())
					bot_list.pb(scc[i]);
			}
			st.pop();
		}

		sort(bot_list.begin(), bot_list.end());
		
		F(i, bot_list.size())
			printf("%d ", bot_list[i]);
		printf("\n");
		
		FE(i,v)
		{
			adj[i].clear();
			rev_adj[i].clear();
		}
	}
	return 0;
}