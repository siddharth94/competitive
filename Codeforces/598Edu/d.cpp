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
#define get(n) scanf("%d",&n);

char mat[1005][1005];
int ans[1005][1005];

bool visited[1005][1005];
queue < pair<int,int> > q;

void bfs()
{
	int tot = 0;
	queue < pii > q2;
	while (!q.empty())
	{
		pii u = q.front();
		int i = u.ft;
		int j = u.sd;

		if (mat[i+1][j] == '.' && !visited[i+1][j])
		{
			q.push(mp(i+1,j));
			visited[i+1][j] = true;
		}
		else if (mat[i+1][j] == '*')
		{
			ans[i][j] += 1;
		}

		if (mat[i-1][j] == '.' && !visited[i-1][j])
		{
			q.push(mp(i-1,j));
			visited[i-1][j] = true;
		}
		else if (mat[i-1][j] == '*')
		{
			ans[i][j] += 1;
		}

		if (mat[i][j+1] == '.' && !visited[i][j+1])
		{
			q.push(mp(i,j+1));
			visited[i][j+1] = true;
		}
		else if (mat[i][j+1] == '*')
		{
			ans[i][j] += 1;
		}

		if (mat[i][j-1] == '.' && !visited[i][j-1])
		{
			q.push(mp(i,j-1));
			visited[i][j-1] = true;
		}
		else if (mat[i][j-1] == '*')
		{
			ans[i][j] += 1;
		}

		tot += ans[i][j];
		q2.push(u);
		q.pop();
	}

	while (!q2.empty())
	{
		pii u = q2.front();
		ans[u.ft][u.sd] = tot;
		q2.pop();
	}
}

int main()
{
	int n,m,k;
	get(n);
	get(m);
	get(k);

	F(i,n)
	{
		scanf("%s",mat[i]);
	}

	F(i,n)
	{
		F(j,m)
		{
			if (mat[i][j] == '.' && ans[i][j] == 0)
			{
				q.push(mp(i,j));
				visited[i][j] = true;	
				bfs();		
			}
		}
	}

	F(i,k)
	{
		int x,y;
		get(x);
		get(y);
		printf("%d\n", ans[x-1][y-1]);
	}
	return 0;
}