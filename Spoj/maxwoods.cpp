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

int main()
{
	int T;
	get(T);
	while (T--)
	{
		char a[205][205],c;
		LL val[205][205];

		memset(val,0,sizeof(val));

		int m,n;
		get(m);
		get(n);

		F(i,m)
			F(j,n)
			{
				c = gc();
				while (c!='0' && c!='#' && c!='T') c=gc();
				a[i][j] = c;
			}

		int ma = 0;

		if ((m-1)&1)
		{ 
			val[m-1][0] = (a[m-1][0]=='T')?1:0;
			ma = val[m-1][0];
		}
		else
		{
			val[m-1][n-1] = (a[m-1][n-1]=='T')?1:0;
			ma = val[m-1][n-1];
		}

		FRE(i,m-1)
		{
			int j = (i&1) ? 0 : n-1;
			for ( ; (i&1) ? j<n : j>-1 ; (i&1) ? j++ : j--)
			{
				if (i&1 && i==m-1 && j==0)
					continue;
				else if ((!(i&1)) && i==m-1 && j==n-1)
					continue;
				else
				{
					if (a[i][j] == '#')
						val[i][j] = 0;
					else if (i&1)
					{
						int tmp1, tmp2;

						if (j>0)
							tmp1 = val[i][j-1];
						else
							tmp1 = -1;

						if (i<n-1)
							tmp2 = val[i+1][j];
						else
							tmp2 = -1;					

						val[i][j] = max(tmp1, tmp2);
					}
					else
					{				
						int tmp1,tmp2;		
						if (j<n-1)
							tmp1 = val[i][j+1];
						else
							tmp1 = -1;

						if (i<n-1)
							tmp2 = val[i+1][j];
						else
							tmp2 = -1;

						val[i][j] = max(tmp1, tmp2);
					}

					if (a[i][j] == 'T')
						val[i][j]++;
				}
			}
		}

		printf("%lld\n",val[0][0]);
	}
	return 0;
}