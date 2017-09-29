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

pair <int, char> color[100005];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n,m;
		get(n);
		get(m);

		char c;

		F(i,m)
		{
			c = gc();
			while (c<'A' || c>'Z') c = gc();
			color[i].second = c;
			get(color[i].first);
		}

		LL MOD = 1000000009;

		sort(color,color+m);

		LL out = 1;

		F(i,m-1)
		{
			if (color[i].second != color[i+1].second)
				out *= (LL)(color[i+1].first - color[i].first);
			while (out >= MOD)
				out -= MOD;
		}

		printf("%lld\n",out);
	}
	return 0;
}