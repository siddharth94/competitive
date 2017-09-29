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

LL com[1000005][6];
const int mod = 1000000007;

void calc(int n)
{
	com[5][0] = 1;
	com[5][1] = 5;
	com[5][2] = 10;
	com[5][3] = 10;
	com[5][4] = 5;
	com[5][5] = 1;
	for (int i=6; i<=n; i++)
		for (int j=0; j<=5; j++)
		{
			if (j==0)
				com[i][j] = 1;
			else
				com[i][j] = (com[i-1][j-1] + com[i-1][j])%mod;
		}
}

int main()
{
	memset(com,0,sizeof(com));
	com[5][0] = 1;
	register int n,t;
	LL ans = 0;
	get(n);

	calc(n);

	if (n&1)
	{
		for (register int i=1; n-i>=12; i+=2)
		{
			t = ((n-i)>>1)-1;
			ans += com[t][5];
			ans %= mod;
		}
	}
	else
	{
		for (register int i=2; n-i>=12; i+=2)
		{
			t= ((n-i)>>1)-1;
			ans += com[t][5];
			ans %= mod;
		}
	}

	printf ("%lld\n",ans);

	return 0;
}