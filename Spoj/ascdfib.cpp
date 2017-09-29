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

int a[2000005];
int c[100005];

int main()
{
	a[1] = 0;
	a[2] = 1;
	R(i, 3, 1100005)
	{
		a[i] = (a[i-1] + a[i-2])%100000;
		
		if (a[i] >= 100000)
			a[i] -= 100000;
	}
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		printf("Case %d: ", __rep);
		int x,y;
		get(x);
		get(y);
		y = x+y;
		memset(c, 0, sizeof(c));
		int m = 100005;
		RE(i,x,y)
		{
			c[a[i]]++;
			m = min(m, a[i]);
		}
		int out = 0;
		R(i,m,100000)
		{
			while(c[i] != 0)
			{
				printf("%d ", i);
				out++;
				if (out == 100)
					break;
				c[i]--;
			}
			if (out == 100)
				break;
		}
		printf("\n");
	}
	return 0;
}