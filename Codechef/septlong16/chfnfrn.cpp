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

bool adj[1005][1005];
queue <int> q;
int bi[1005];
bool visited[1005];

bool bfs(int n)
{
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		F(i,n)
		{
			if (i != top && adj[top][i] == 1 && visited[i] && bi[i] == bi[top])
				return false;
			if (i!= top && adj[top][i] == 1 && !visited[i])
			{
				visited[i] = true;
				
				if (bi[i] != bi[top])
					bi[i] = !bi[top];
				else return false;
				q.push(i);
			}
		}
	}
	return true;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;
		get(n);
		get(m);

		memset(adj, 0, sizeof adj);

		F(i,m)
		{
			int x,y;
			get(x);
			get(y);
			adj[x-1][y-1] = adj[y-1][x-1] = true;
		}

		F(i,n)
			F(j,n)
				adj[i][j] = !adj[i][j];

		memset(visited, 0, sizeof visited);
		memset(bi,-1,sizeof bi);

		bool ans = true;

		F(i,n)
		{
			if (!visited[i])
			{
				bi[i] = 0;
				visited[i] = true;
				q.push(i);
				if (bfs(n))
					continue;
				else
				{
					ans = false;
					break;
				}
			}
		}
		if (ans)
			printf("YES\n");
		else printf("NO\n");
		
		while (!q.empty())
			q.pop();
	}
	return 0;
}