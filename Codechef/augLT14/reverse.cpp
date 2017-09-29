#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define P pair <int,int> 

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

vector < pair <int,int> > adj[100005];
bool visited[100005]; // if vertex i has been visited
priority_queue< P , vector< P >, greater< P > > cost;
int cost_n;

void dijkstra(int n)
{
	for (int i=1; i<=n; i++)
	{
		if (cost.size() == 0) //Priority queue gets empty
			return;
		P tmp = cost.top();
		if ((cost.top()).second == n) // Reached the last vertex
			return;
		visited[(cost.top()).second] = true; // mark the current vertex as visited
		for (vector < P > :: iterator it = adj[tmp.second].begin(); it<adj[tmp.second].end(); ++it)
		{
			if (visited[(*it).second]) // if the selected vertex in adj list is already visited
				continue;
			else
			{
				if ((*it).first == 0) // if a direct path is there
				{
					cost.push(mp(tmp.first,(*it).second));	// push this in the queue
					if ((*it).second == n && cost_n > (tmp.first))	// keep track of minimum cost of last vertex
						cost_n = tmp.first;
				}
				else // if reverse arrow is there
				{
					cost.push(mp((tmp.first)+1,(*it).second));	// push in the queue with increases cost
					if ((*it).second == n && cost_n > (tmp.first)+1)	// keep track of minimum cost of last vertex
						cost_n = (tmp.first)+1;
				}
			}
		}
		while (cost.size() > 0 && visited[(cost.top()).second]) // if some already visited node is on top of queue
			cost.pop();
	}
	return;
}

int main()
{
	int n,m;
	get(n);
	get(m);

	cost_n = 999999;
	fill_n(visited, n+3, false);

	int x,y;
	F(i,m)
	{
		get(x);
		get(y);
		if(x==y)
			continue;
		adj[x].push_back(make_pair(0,y));
		adj[y].push_back(make_pair(1,x));
	}
	cost.push(mp(0,1));
	dijkstra(n);
	printf("%d\n",(cost_n == 999999)?-1:cost_n);
	return 0;
}