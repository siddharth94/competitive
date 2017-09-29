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

LL inf = 1ll<<63 - 1;
double e = 1e-128;

struct line
{
	int a,b,c;
	double r1,r2,r3;
}lines[100005];

bool cmp(struct line p, struct line q)
{
	if (abs(p.r1 - q.r1) < e)
	{
		if (abs(p.r2 - q.r2) < e)
			return p.r3 < q.r3;

		return p.r2 < q.r2;
	}
	else return p.r1 < q.r1;
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
			get(lines[i].a);
			get(lines[i].b);
			get(lines[i].c);

			if (lines[i].b != 0) lines[i].r1 = (lines[i].a*1.0)/lines[i].b; else lines[i].r1 = inf*1.0;
			if (lines[i].b != 0) lines[i].r2 = (lines[i].c*1.0)/lines[i].b; else lines[i].r2 = inf*1.0;
			if (lines[i].a != 0) lines[i].r3 = (lines[i].c*1.0)/lines[i].a; else lines[i].r3 = inf*1.0;
		}
		sort(lines, lines+n, cmp);

		int types;
		int max_type = 1;
		F(i,n-1)
		{
			types = 1;
			while (i < n-1 && abs(lines[i].r1 - lines[i+1].r1) < e)
			{
				if (abs(lines[i].r2 - lines[i+1].r2) > e || abs(lines[i].r3 - lines[i+1].r3) > e)
					types++;
				i++;
			}
			max_type = max(max_type, types);
		}

		printf("%d\n", max_type);
	}
	return 0;
}