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

int arr[100005];
int dp[100005][30];
int sum[100005];

int main()
{
	int n,m;
	get(n);
	get(m);
	
	int csum = 0, p=1, shift = 1;
	char c = gc();

	while (c > '9' || c < '0') c = gc();
	arr[0] = (int)(c-'0');
	csum = arr[0];
	dp[0][0] = csum;
	
	R(i,1,n)
	{
		c = gc();
		arr[i] = (int)(c-'0');
		csum += arr[i];
		if (i+1 == p)
		{
			dp[0][shift] = csum;
			shift++;
			p = 1<<shift;
		}
	}

	R(i,1,n)
	{
		for (int j=0; (i-1 + (1<<j)) < n; j++)
			dp[i][j] = dp[i-1][j] - arr[i-1] + arr[i-1+(1<<j)];
	}

	while (m--)
	{
		int type;
		get(type);

		if (type)
		{
			
		}
	}

	return 0;
}