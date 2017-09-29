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

map <string,int> city;
vector < pii > adj[100005];
priority_queue < pii , vector < pii > , greater < pii > > pq;
bool visited [100005];
int d[100005];

LL dijkstra(int b, int n)
{
	F(i,n)
	{
		pii tmp = pq.top();
		visited[tmp.second] = true;

		if (tmp.second == b)
			return tmp.first;

		for (vector < pii > :: iterator it = adj[tmp.second].begin(); it != adj[tmp.second].end(); ++it)
		{
			if (visited[(*it).second])
				continue;
			else if (d[(*it).second] > (tmp.first)+((*it).first) | d[(*it).second] == 0)
			{
				pq.push(mp((tmp.first)+((*it).first), (*it).second));
				d[(*it).second] = (tmp.first)+((*it).first);	
			}
		}
		while (pq.size()>0 and visited[(pq.top()).second])
			pq.pop();
	}
}

void cl()
{
	F(i,10005)
		adj[i].clear();
	while (pq.size()>0)
		pq.pop();
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n, p, r;
		int nr, cost;
		string name, name1;
		char na[15],na1[15];

		get(n);

		F(i,n)
		{
			scanf("%s",na);
			name = na;
			city[name] = i+1;
			get(p);
			F(j,p)
			{
				get (nr);
				get (cost);
				adj[i+1].push_back(mp(cost,nr));
			}
		}

		get(r);
		F(i,r)
		{
			memset(visited, false, sizeof(visited));
			memset(d, 0, sizeof(d));
			scanf ("%s %s", na, na1);
			// cin >> name >> name1;
			name = na;
			name1 = na1;
			int a = city[name];
			pq.push(mp(0,a));
			d[a] = 0;
			printf("%lld\n", dijkstra(city[name1],n));
			while (pq.size())
				pq.pop();
		}
		scanf("\n");

		cl();
	}
	return 0;
}