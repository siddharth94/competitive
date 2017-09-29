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

LL power (LL b, LL p)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	LL p1 = p,ans=1;
	if (p%2 == 0)
	{
		ans = power(b,p/2);
		ans = (ans * ans);
	}
	else if (p%2 == 1)
	{
		ans = power (b,p/2);
		ans = (((ans * ans) ) *b);
	}
	return ans;
}

LL loga(LL k, LL b)
{
	if (k==1 || b==)1
		return 0;
	else if (k < b)
		return 0;
	else
	{
		LL tmp = 1;
		while (k >= pow(b,tmp))
			tmp++;
		tmp--;
		return tmp;
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL n,k;
		LL coins = 0;
		getll(n);	
		getll(k);

		// F(i,99)
		// 	a[i] = k;
		
		while (n>0)
		{
			LL l = (LL)(loga(n,k));
			// cout << l << endl;

			LL po = (LL)pow(k,l);
			LL q = n/po;
			// assert(q<=k);
			coins += q;
			n -= q*po;
		}
		printf("%lld\n",coins);
	}
	return 0;
}