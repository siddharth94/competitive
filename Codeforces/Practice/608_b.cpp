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

char a[200005];
char b[200005];

LL mod1 = 1e9+7;
LL mod2 = 1e9+21;

int main()
{
	scanf("%s",a);
	scanf("%s",b);

	int n = strlen(a);
	int m = strlen(b);

	LL n1,n2;
	LL m1,m2;
	n1 = n2 = 0;
	m1 = m2 = 0;

	F(i,n)
	{
		n1 = (n1<<1) + (a[i] - '0');
		n2 = (n2<<1) + (a[i] - '0');

		m1 = (m1<<1) + (b[i] - '0');
		m2 = (m2<<1) + (b[i] - '0');
	
		if (n1 >= mod1)
			n1 %= mod1;
	
		if (n2 >= mod2)
			n2 %= mod2;
	}

	F(i,n)
	return 0;
}