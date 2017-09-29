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
#define get(x) scanf("%d",&x)

// inline void get(int &x)
// {
//     register int c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }

vector <int> adj[100005];
int has_cat[100005];
bool visited [100005];

int dfs(int root, int maxlen, int m)
{
	if (maxlen > m)
		return 0;

	int ans = 0;
	if (has_cat[root])
		maxlen++;
	else
		maxlen = 0;
	bool leaf = true;
	F(i,adj[root].size())
	{
		if (!visited[adj[root][i]])
		{
			visited[adj[root][i]] = true;
			leaf = false;
			ans += dfs(adj[root][i], maxlen, m);
		}
	}
	if (leaf && maxlen<=m)
		return 1;
	return ans;
}

int main()
{
	int n,m;
	get(n);
	get(m);

	F(i,n)
		get(has_cat[i]);

	F(i,n-1)
	{
		int x,y;
		get(x);
		get(y);
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	visited[0] = true;
	printf("%d\n", dfs(0,0,m));
	return 0;
}