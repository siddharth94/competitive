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

vector <int> adj[10005];
int prd[10005];
int dp[10005][105];
bool visited[10005];
queue <int> q;
int parent[10005];
int ans[10005][105];
bool acal[10005];

void bfs()
{
	memset(visited, false, sizeof(visited));
	while (!q.empty())
	{
		visited[q.front()] = true;
		int sz = adj[q.front()].size();
		F(i,sz)
		{
			if (!visited[adj[q.front()][i]])
			{
				q.push(adj[q.front()][i]);
				parent[adj[q.front()][i]] = q.front();
			}
		}
		q.pop();
	}
}

void builddp(int b, int n)
{
	F(i,10004)
		F(j,104)
			dp[i][j] = 999999;
	F(i,n)
	{
		memset(visited, false, sizeof(visited));
		while (!q.empty())
			q.pop();
		q.push(i);
		visited[parent[i]] = true;
		while (!q.empty())
		{
			int city = q.front();
			visited[city] = true;
			if (dp[i][prd[city]] > city)
				dp[i][prd[city]] = city;
			int sz = adj[city].size();
			F(j,sz)
				if (!visited[adj[city][j]])
					q.push(adj[city][j]);
			q.pop();
		}
	}
}

int calc(int i, int j, int b)
{
	if (i == b && dp[i][j] != 999999)
		ans[i][j] = dp[i][j];

	else if (dp[i][j] == 999999 && i != b)
		ans[i][j] = calc(parent[i], j, b);

	return ans[i][j];
}

void buildans(int b, int n, int k)
{
	memset(ans, -1, sizeof(ans));
	memset(acal, false, sizeof(acal));
	F(i,n)
		R(j,1,k)
		{
			ans[i][j] = calc(i,j,b);
		}
}

int main()
{
	int n,k;
	get(n);
	get(k);
	int b;
	get(b);
	b--;
	parent[b] = -1;

	F(i,n-1)
	{
		int x,y;
		get(x);
		get(y);
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	q.push(b);
	bfs();

	F(i,n)
		get(prd[i]);

	builddp(b,n);
	buildans(b,n,k);

	int qr;
	get(qr);
	F(i,qr)
	{
		int a,p;
		get(a);
		get(p);
		a--;
		printf("%d\n",ans[a][p]);
	}
	return 0;
}