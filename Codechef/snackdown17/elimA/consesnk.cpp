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

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

LL s[100005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL n,l,a,b;
		getll(n);
		getll(l);
		getll(a);
		getll(b);

		F(i,n)
		{
			getll(s[i]);
		}	

		sort(s,s+n);

		LL ldist = 0ll;
		LL snakes_at_a = 0ll;

		LL rdist = 0ll;
		LL snakes_at_b = 0ll;

		for(int i=0; i<n; i++)
		{
			if (s[i] < a)
			{
				ldist += a-s[i];
				snakes_at_a++;
				s[i] = a;
			}
			if (s[i] > b-l)
			{
				rdist += s[i]-(b-l);
				snakes_at_b++;
				s[i]=b-l; 
			}
		}

		LL lline = snakes_at_a*l;
		LL rline = snakes_at_b*l;

		
	}
	return 0;
}