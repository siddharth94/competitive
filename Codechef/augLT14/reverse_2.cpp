#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
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

vector <pair <int,int> > adj[100005];
queue <int> q;
int cost[100005];
bool in_q[100005];

void bfs()
{
	while (!q.empty())
	{
		// visited[q.front()] = true;
		for (vector <pii > :: iterator it=adj[q.front()].begin(); it!=adj[q.front()].end(); ++it)
		{
			if (!in_q[(*it).second])
			{
				in_q[(*it).second]=true;
				q.push((*it).second);
			}
			if ((cost[(*it).second] > cost[q.front()]+(*it).first) || (cost[(*it).second]==0))
				cost[(*it).second] = cost[q.front()]+(*it).first;
		}
		in_q[q.front()]=false;
		q.pop();
	}
	return;
}

int main()
{
	register int n,m,x,y;
	get(n);
	get(m);

	fill_n(in_q, n+3, false);
	// fill_n(cost, n+3, 999999);

	F(i,m)
	{
		get(x);
		get(y);
		if(x==y)
			continue;
		adj[x].push_back(make_pair(0,y));
		adj[y].push_back(make_pair(1,x));
	}
	q.push(1);
	cost[1] = 1;
	in_q[1] = true;
	bfs();
	printf("%d\n",(cost[n]==0)?-1:--cost[n]);
	return 0;
}