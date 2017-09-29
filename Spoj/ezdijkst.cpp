#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <long long, long long>
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

vector < pii > adj[10005]; // <cost,vertex>
priority_queue < pii , vector < pii > , greater < pii > > cost;
bool visited[10005];

LL dijkstra(LL b, LL v)
{
	for (LL i=1; i<=v; i++)
	{
		if (cost.size() == 0)
			return -1;

		pii tmp = cost.top();
		visited[tmp.second] = true;

		if (tmp.second == b)
			return tmp.first;

		for (vector < pii > :: iterator it = adj[tmp.second].begin(); it != adj[tmp.second].end(); ++it)
		{
			if (visited[(*it).second])
				continue;
			else
				cost.push(mp((tmp.first)+((*it).first),(*it).second));
		}
		while (cost.size() > 0 and visited[(cost.top()).second])
			cost.pop();
	}
	return -1;
}

void cl()
{
	F(i,10005)
		adj[i].clear();
	while (cost.size() > 0)
		cost.pop();
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		memset(visited, false, sizeof(visited));
		LL v,k,a,b,c;
		getll(v);
		getll(k);

		F(i,k)
		{
			getll(a);
			getll(b);
			getll(c);
			adj[a].push_back(mp(c,b));
			// adj[b].push_back(mp(c,a));
		}

		getll(a);
		getll(b);

		cost.push(mp(0,a));
		visited[a] = true;

		LL ans = dijkstra(b,v);

		if (ans == -1)
			printf("NO\n");
		else printf("%lld\n",ans);

		cl();
	}
	return 0;
}