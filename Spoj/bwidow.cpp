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

struct loop
{
	int r,R;
	int idx;
};

loop rr[1005];

bool comp1(loop a, loop b)
{
	if (a.r != b.r)
		return  a.r < b.r;
	else
		return a.R < b.R;
}

bool comp(loop a, loop b)
{
	return  a.R < b.R;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		F(i,n)
		{
			int r,R;
			get(r);
			get(R);
			rr[i].r = r;
			rr[i].R = R;
			rr[i].idx = i+1;
		}
		sort(rr, rr+n, comp1);
		loop maxi = rr[n-1];
		sort(rr, rr+n, comp);
		if (maxi.r == rr[n-1].r)
		{
			if (maxi.r > rr[n-2].R)
				printf("%d\n", maxi.idx);
			else printf("-1\n");
		}
		else
		{
			if (maxi.r > rr[n-1].R)
				printf("%d\n", maxi.r);
			else
				printf("-1\n");
		}
	}
	return 0;
}