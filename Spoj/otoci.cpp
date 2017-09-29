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

int pen[30005];
vector <int> bridge[30005];
bool visited [30000];
queue <int> qu;
stack <int> st;
int sum;

bool bfs(int b)
{
	while (!qu.empty())
	{
		for (vector<int> :: iterator it = bridge[qu.front()].begin(); it != bridge[qu.front()].end(); ++it)
		{
			if ((*it)==b)
				return true;
			if (visited[*it])
				continue;
			qu.push(*it);
			visited[*it] = true;
		}
		qu.pop();
	}
	return false;
}

bool dfs(int b)
{
	if (st.empty())
		return false;
	else
	{
		for (vector<int> :: iterator it = bridge[st.top()].begin(); it != bridge[st.top()].end(); ++it)
		{
			if (visited[*it])
				continue;
			if ((*it) == b)
			{
				sum += pen[b];
				return true;
			}
			visited[*it] = true;
			sum += pen[(*it)];
			st.push(*it);
			if (dfs(b)) return true;
			st.pop();
			sum -= pen[*it];
		}
		return false;
	}
}

int main()
{
	register int n;
	get(n);

	F(i,n)
	{
		get(pen[i]);
		bridge[i].push_back(i);
	}
	
	register int q;
	get(q);
	
	char str[50];
	register int a,b;

	F(i,q)
	{
		scanf("%s",str);
		if(str[0] == 'b')
		{
			get(a);
			get(b);
			a--;
			b--;
			memset(visited, false, sizeof(visited));
			// qu.erase();
			while (!qu.empty())
				qu.pop();
			qu.push(a);
			visited[a] = true;
			if (bfs(b))
				printf("no\n");
			else 
			{
				printf("yes\n");
				bridge[a].push_back(b);
				bridge[b].push_back(a);
			}
		}
		if(str[0] == 'e')
		{
			get(a);
			get(b);
			if (a==b)
			{
				printf("%d\n",pen[--a]);
				continue;
			}
			a--;
			b--;
			// st.erase();
			while (!st.empty())
				st.pop();
			memset(visited, false, sizeof(visited));
			st.push(a);
			visited[a] = true;
			sum = pen[a];
			if (!dfs(b))
			// if (sum == -1)
				printf("impossible\n");
			else printf("%d\n",sum);
		}
		if (str[0] == 'p')
		{
			get(a);
			get(b);
			a--;
			pen[a] = b;
		}
	}
	return 0;
}