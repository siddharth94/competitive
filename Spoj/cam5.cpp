#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
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

int mark[100005];
vector<int> adj[100005];
queue <int> q;

int bfs()
{
	while (!q.empty())
	{
		int i = q.front();
		int sz = adj[i].size();
		mark[i] = -1;

		F(j,sz)
		{
			if (mark[adj[i][j]] == -1)
				continue;
			else
			{
				q.push(adj[i][j]);
				mark[adj[i][j]] = -1;
			}
		}
		q.pop();
	}
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n,e,x,y;
		get(n);
		get(e);

		F(i,e)
		{
			get(x);
			get(y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		memset(mark, 0, sizeof(mark));

		int count = 0;

		// while ((p = lower_bound(mark,mark+n,0)) != mark+n)
		for (int i=0; i<n; i++)
		{
			if (mark[i] == -1)
				continue;
			else
			{
				q.push(i);
				mark[i] = -1;
				bfs();			
				count++;
			}
		}

		printf("%d\n",count);

		while (!q.empty())
			q.pop();
		F(i,n)
			adj[i].clear();
	}
	return 0;
}