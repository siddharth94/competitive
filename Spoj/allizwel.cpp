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

char mat[105][105];
char s[] = "ALLIZZWELL";
bool visited[105][105];
int r,c;

bool dfs(int x, int y, int dep)
{
	if (dep == 10)
		return true;
	for (int i=x-1; i<=x+1; i++)
		for (int j=y-1; j<=y+1; j++)
		{
			if (visited[i][j])
				continue;
			if (i>=0 && i<r && j>=0 && j<c)
				if (s[dep] == mat[i][j])
				{
					visited[i][j] = true;
					if (dfs(i,j,dep+1))
						return true;
					visited[i][j] = false;
				}
		}
	return false;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		queue < pii > q;
		get(r);
		get(c);
		F(i,r)
		{
			F(j,c)
			{
				mat[i][j] = '\n';
				while(mat[i][j] == '\n')
					scanf("%c",&mat[i][j]);
				if (mat[i][j] == s[0])
					q.push(mp(i,j));
			}
		}
		bool ans = false;
		while (!q.empty())
		{
			int x = q.front().ft;
			int y = q.front().sd;
			q.pop();
			memset(visited, 0, sizeof(visited));
			visited[x][y] = true;
			ans = dfs(x,y,1);
			if (ans)
				break;
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}