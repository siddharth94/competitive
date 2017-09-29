#include <bits/stdc++.h>
using namespace std;

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

LL mat[105][105];
LL dp1[105][105][105], dp2[105][105][105];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int m,n;
		LL ma = -pow(2,62);
		get(m);
		get(n);
		F(i,m)
			F(j,n)
			{
				getll(mat[i][j]);
				dp1[i][j][1] = mat[i][j];
				dp2[i][j][1] = mat[i][j];
			}
		for (int i=2; i<=min(m,n); i++)
			if (i&1)
				F(x,m+1-i)
					F(y,n+1-i)
					{
						dp1[x][y][i] = dp1[x][y][(i>>1)] + mat[x+(i>>1)][y+(i>>1)] + dp1[x+1+(i>>1)][y+1+(i>>1)][(i>>1)];
						dp2[x][y][i] = dp2[x+1+(i>>1)][y][(i>>1)] + mat[x+(i>>1)][y+(i>>1)] + dp2[x][y+1+(i>>1)][(i>>1)];
						ma = max(ma, dp1[x][y][i] + dp2[x][y][i] - mat[x+(i>>1)][y+(i>>1)]);
					}
			else
				F(x,m+1-i)
					F(y,n+1-i)
					{
						dp1[x][y][i] = dp1[x][y][(i>>1)] + dp1[x+(i>>1)][y+(i>>1)][(i>>1)];
						dp2[x][y][i] = dp2[x][y+(i>>1)][(i>>1)] + dp2[x+(i>>1)][y][(i>>1)];
						ma = max(ma, dp1[x][y][i] + dp2[x][y][i]);
					}
		printf("%lld\n",ma);
		memset(mat,0,sizeof(mat));
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
	}
	return 0;
}