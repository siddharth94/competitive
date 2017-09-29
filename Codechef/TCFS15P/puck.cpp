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

struct node
{
	int even, odd, sum, children;

	void init(int a)
	{
		if (a&1)
			odd = 1, even = 0;
		else even = 1 , odd = 0;
		sum = a;
		children = 0;
	}

	void merge(node l, node r)
	{
		even = l.even + r.even;
		odd = l.odd + r.odd;
		sum = l.sum + r.sum;
		children = 2 + l.children + r.children;
	}
};

int main()
{

	return 0;
}