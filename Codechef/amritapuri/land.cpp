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

int giv[105][105];
int dp1[105][105][105], dp2[105][105][105];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int m,n;
		get(m);
		get(n);

		F(i,m)
		{
			F(j,n)
			{
				get(giv[m][n]);
			}
		}

		int ma = min(m,n);

		for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++)
			{
				dp1[i][j][1]=giv[i][j];
				dp2[i][j][1]=giv[i][j];
			}

		int ans;

		for (int s=2; s<ma; s++)
		{
			for (int i=0; i<m-s; i++)
			{
				for (int j=0; j<n-s; j++)
				{
					if (s&1)
					{
						dp1[i][j][s] = dp1[i][j][s>>1] + dp1[i+(s>>1)+1][j+(s>>1)+1][s>>1] + giv[i+(s>>1)][j+(s>>1)];
						dp2[i][j][s] = dp1[i][j+(s>>1)+1][s>>1] + dp2[i+(s>>1)+1][j][s>>1] + giv[i+(s>>1)][j+(s>>1)];
					}
					else
					{
						dp1[i][j][s] = dp1[i][j][s>>1] + dp1[i+(s>>1)][j+(s>>1)][s>>1];
						dp2[i][j][s] = dp2[i][j+(s>>1)][s>>1] + dp2[i+(s>>1)][j][s>>1];
					}
					ans = dp1[i][j][s] + dp2[i][j][s] - giv[i+(s>>1)][j+(s>>1)];
					if (ma < ans)
						ma = ans;
				}
			}
		}
		printf("%d\n", ma);
	}
	return 0;
}