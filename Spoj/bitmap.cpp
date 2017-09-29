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

char mat[190][190];
queue < pii > q;
int ans[190][190];
bool visited[190][190];
int n,m;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().ft;
		int y = q.front().sd;
		for (int i=x-1; i<=x+1; i++)
		{
			for (int j=y-1; j<=y+1; j++)
			{
				if ((x==i ^ y==j) && (i>=0 && i<n) && (j>=0 && j<m))
				{
					if (visited[i][j])
						continue;
					visited[i][j] = true;
					ans[i][j] = ans[x][y] + 1;
					q.push(mp(i,j));
				}
			}
		}
		q.pop();
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		memset(ans, -1, sizeof(ans));
		memset(visited, 0, sizeof(visited));
		get(n);
		get(m);
		F(i,n)
		{
			scanf("%s", mat[i]);
			F(j,m)
				if (mat[i][j] == '1')
				{
					q.push(mp(i,j));
					visited[i][j] = true;
					ans[i][j] = 0;
				}
		}
		bfs();
		F(i,n)
		{
			F(j,m)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}