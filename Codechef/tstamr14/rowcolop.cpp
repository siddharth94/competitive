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

int r[400000];
int c[400000];

int main()
{
	int n;
	get(n);
	int q;
	get(q);

	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));

	string s;
	int u,x,maxr = 0,maxc = 0;

	F(i,q)
	{
		cin >> s;
		get(u);
		get(x);
		if (!s.compare("RowAdd"))
		{
			r[u-1]+=x;
			if (r[u-1] > maxr)
				maxr = r[u-1];
		}
		else
		{
			c[u-1]+=x;
			if (maxc < c[u-1])
				maxc = c[u-1];
		}
	}

	printf("%d\n",maxc+maxr);
	return 0;
}