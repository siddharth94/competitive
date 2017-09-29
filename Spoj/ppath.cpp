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

int m[10005];
vector <int> p;
vector <int> adj[1100];
queue <int> q;
bool visited [1100];
int level[1100];
map <int,int> pp;

void sieve()
{
	memset(m,0,sizeof(m));
	register int b=0;
	for (register int i=2; i<10001; i++)
	{
		if (m[i] == 1)
			continue;
		else
		{
			if (i>1000)
				p.push_back(i);
			register LL j=(LL)i*i;
			for (; j<10001; j+=i)
				m[j] = 1;
		}
	}
	return;
}

bool valid (int i, int j)
{
	int a,b;
	a = p[i];
	b = p[j];
	int d1,d2,count=0;

	for (int i=0; i<4; i++)
	{
		d1 = a%10;
		d2 = b%10;
		if (d1 != d2)
			count++;
		a/=10;
		b/=10;
	}
	if (count == 1)
		return true;
	else return false;
}

int bfs (int t)
{
	while (!q.empty())
	{
		int k = q.front();
		int sz = adj[k].size();
		visited[k] = true;
		for (int i=0; i<sz; i++)
		{
			if (visited[adj[k][i]])
				continue;
			else if (adj[k][i] == t)
				return level[k]+1;
			else
			{
				q.push(adj[k][i]);
				visited[adj[k][i]] = true;
				level [adj[k][i]] = level[k]+1;
			}
		}
		q.pop();
	}
	return -1;
}

int main()
{
	int T;
	get(T);
	sieve();
	while (T--)
	{
		int sz = p.size();
		F(i,sz)
		{
			pp[p[i]] = i;
			F(j,sz)
			{
				if (i==j)
				{
					adj[i].push_back(i);
				}
				else if (valid(i,j))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		int s,t;
		get(s);
		get(t);

		memset(visited, false, sizeof(visited));
		memset(level, 0, sizeof(level));

		int in = pp[s], out = pp[t];
		q.push(in);
		visited[in] = true;
		level[in] = 0;

		if (in == out){
			printf("0\n");
			continue;
		}


		int ans = bfs(out);
		if (ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
		while (!q.empty())
			q.pop();
	}
	return 0;
}