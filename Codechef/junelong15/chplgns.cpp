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

pii a[100005];
int pos[100005];

bool comp(pii a, pii b)
{
	return (a.ft < b.ft);
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n, m, x, y;
		get(n);
		F(i,n)
		{
			get(m);
			int max = -1000000005;
			F(j,m)
			{
				get(x);
				get(y);
				if (y > max)
					max = y;
			}
			a[i] = mp(max,i);
		}
		sort(a,a+n,comp);
		F(i,n)
		{
			pos[a[i].sd] = i;
		}
		F(i,n)
			printf("%d ", pos[i]);
		printf("\n");
	}
	return 0;
}