#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
#define F(i,n) for(long long i=0;i<n;i++)
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

LL a[23];
int dp[10][3000000];
LL sum[3000000];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		LL n,k;
		LL psum = 0;
		getll(n);
		getll(k);
		F(i,n)
		{
			getll(a[i]);
			psum += a[i];
		}

		// if (k==1)
		// {
		// 	printf("yes\n");
		// 	continue;
		// }

		if (psum % k || n < k)
		{
			printf("no\n");
			continue;
		}

		LL x = psum/k;

		if (x==0)
		{
			printf("yes\n");
			continue;
		}

		dp[0][0] = 1;
		LL ns = pow(2,n);
		F(i,k)
		{
			F(j,ns)
			{
				LL tsum = 0;
				if (dp[i][j] == 0)
					continue;
				if (sum[j] == 0)
				{
					F(z,n)
					{
						if (j & (1<<z))
							tsum += a[z];
					}
					sum[j] = tsum;
				}
				tsum = sum[j];
				tsum -= i*x;
				F(z,n)
				{
					if (j & (1<<z))
						continue;
					tsum += a[z];
					LL n_bitmsk = j | (1<<z);
					sum[n_bitmsk] = tsum + (i*x);
					if (tsum == x)
						dp[i+1][n_bitmsk] = 1;
					else if (tsum < x)
						dp[i][n_bitmsk] = 1;
					tsum -= a[z];
				}
			}
		}
		if (dp[k][ns-1])
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}