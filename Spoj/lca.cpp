#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int parent[1005];
vector<int> children[1005];
int level[1005];
queue<int> q;
// int lca[1005][1005];

int bfs()
{
	if (q.empty())
		return 0;
	for (vector<int>::iterator it=children[q.front()].begin(); it!=children[q.front()].end(); ++it)
	{
		q.push((*it));
		level[(*it)] = level[q.front()]+1;
	}
	q.pop();
	bfs();
}

int main()
{
	int T;
	get(T);
	int f=T;
	while (T--)
	{
		F(i,1005)
		{
			level[i]=0;
			parent[i]=0;
			children[i].clear();
		}
		printf("Case %d:\n",f-T);
		int n;
		get(n);
		int root = n*(n+1)/2;
		F(i,n)
		{
			int m;
			get(m);
			F(j,m)
			{
				int a;
				get(a);
				root -= a;
				parent[a-1] = i;
				children[i].push_back(a-1);
			}
		}
		level[root-1]=0;
		q.push(root-1);
		bfs();
		int q;
		get(q);
		F(i,q)
		{
			int v,w;
			get(v);
			get(w);
			int v1 = v--;
			int w1 = w--;
			// if (lca[])
			while (level[v]!=level[w])
			{
				if (level[v]>level[w])
					v=parent[v];
				else 
					w=parent[w];
			}
			while (v!=w)
			{
				v=parent[v];
				w=parent[w];
			}
			// lca[v1][w1]=lca[w1][v1]=v;
			printf("%d\n",v+1);
		}
	}
	return 0;
}