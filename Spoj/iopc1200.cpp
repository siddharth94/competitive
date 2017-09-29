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
map <vector<int>, int> hash;
int id[10005];
LL mod = 1000000007;
LL fact[10005];
LL ans = 1LL;

void fac()
{
	fact[0] = 1;
	R(i,1,10005)
	{
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
	}
}

int genid(vector <int> v)
{
	if (hash.find(v) == hash.end())
		hash[v] = hash.size();
	return hash[v];
}

void dfs(int x, int p)
{
	int n = adj[x].size();
	vector <int> children;
	
	F(i,n)
	{
		if (adj[x][i] != p)
		{
			dfs(adj[x][i], x);
			children.pb(id[adj[x][i]]);
		}
	}

	sort(children.begin(), children.end());

	n = children.size();
	int count = 1;
	R(i,1,n)
	{
		if (children[i] == children[i-1])
			count++;
		else
		{
			ans *= fact[count];
			ans %= mod;
			count = 1;
		}
	}
	ans *= fact[count];
	ans %= mod;

	id[x] = genid(children);
}

int main()
{
	int T;
	get(T);
	fac();
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,x,y;
		get(n);
		F(i,n-1)
		{
			get(x);
			get(y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		dfs(0,-1);
		printf("%lld\n",ans);
		F(i,n)
			adj[i].clear();
		ans = 1;
	}
	return 0;
}