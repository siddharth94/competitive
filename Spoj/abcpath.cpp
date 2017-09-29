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

char mat[55][55];
bool visited[55][55];

int main()
{
	int h=-1,w=-1;
	int c = 1;
	while (1)
	{
		F(i,51)
			F(j,51)
				visited[i][j] = false;
		get(h);
		get(w);
		if (h==0)
			break;

		queue < pii > q;
		F(i,h)
		{
			F(j,w)
			{
				scanf("%c",&mat[i][j]);
				if (mat[i][j] == 'A')
					q.push(mp(i,j));
			}
			scanf("\n");
		}
		if (q.empty())
		{
			printf("Case %d: 0\n", c);
			c++;
			continue;
		}
		char last = 'A';
		while (!q.empty())
		{
			int x = q.front().ft;
			int y = q.front().sd;
			q.pop();
			last = mat[x][y];
			for (int i=x-1; i<=x+1; i++)
				for (int j=y-1; j<=y+1; j++)
				{
					if (visited[i][j])
						continue;
					if (i>=0 && i<h && j>=0 && j<w)
						if ((mat[i][j] == mat[x][y]+1) && !visited[i][j])
						{
							visited[i][j] = true;
							q.push(mp(i,j));
						}
				}
		}
		printf("Case %d: %d\n", c, last-'A'+1);
		c++;
	}
	return 0;
}