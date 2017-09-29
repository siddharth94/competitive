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

int main()
{
	int q,a,b,x,y,minit,ninit,m,n,slevel,hm,hn,ans=0;
	get(q);
	char c;
	bool flip = false;
	while(q--)
	{
		c = gc();
		while (c!='Q') c=gc();
		c = gc();

		if (c=='i')
			flip = !flip;
		else
		{
			get(a);
			get(b);
			x = a;
			y = b;
			minit = log2(x);
			ninit = log2(y);
			m = minit;
			n = ninit;
			while (m!=n)
			{
				if (x>y)
				{
					x>>=1;
					m--;
				}
				else
				{
					y>>=1;
					n--;
				}
			}
			slevel = m;
			while (x!=y)
			{
				x>>=1;
				y>>=1;
				slevel--;
			}
			hm = minit - slevel;
			hn = ninit - slevel;
			if (flip)
			{
				if (c=='r')
					c='b';
				else c='r';
			}
			if (c=='r')
			{
				ans = hm>>1;
				if (!(slevel&1) && minit&1)
					ans++;
				ans += hn>>1;
				if (!(slevel&1) && ninit&1)
					ans++;
				if (slevel&1)
					ans++;
			}
			else
			{
				ans = hm>>1;
				if (slevel&1 && !(minit&1))
					ans++;
				ans += hn>>1;
				if (slevel&1 && !(ninit&1))
					ans++;
				if (!(slevel&1))
					ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}