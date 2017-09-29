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

LL ways[1005][1005];
int a[1005];

int main()
{
	int mod = 1e9+7;
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m,s;
		get(n);
		get(m);
		get(s);
		
		F(i,m)
			get(a[i]);

		memset(ways, 0, sizeof ways);
		ways[s-1][0] = 1;


		for (int i=0; i<m; i++) // ith pass
		{
			F(j,n) // ball is with jth dog
			{
				if (j+a[i] < n)
					ways[j][i+1] += ways[j+a[i]][i];
				if (j-a[i] >= 0)
					ways[j][i+1] += ways[j-a[i]][i];
				ways[j][i+1] %= mod;
			}
		}

		F(i,n)
			printf("%lld ", ways[i][m]);
		printf("\n");
	}
	return 0;
}