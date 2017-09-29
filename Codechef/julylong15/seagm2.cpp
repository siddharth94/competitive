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

LL pw = 8588608ll;

double power (double b, LL p)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	LL p1 = p;
	double ans=1;
	if (p%2 == 0)
	{
		ans = power(b,p/2);
		ans = (ans * ans);
	}
	else if (p%2 == 1)
	{
		ans = power (b,p/2);
		ans = (ans * ans * b);
	}
	return ans;
}

int main()
{
	LL r = 1e12;
	double k = 1/r;
	printf("%.12lf\n", k);
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;
		get(n);
		get(m);
		double sum = 0, ser = 0;
		F(i,n)
		{
			double ip = 1;
			F(j,m)
			{
				double tmp;
				scanf("%lf", &tmp);
				ip *= tmp;
			}
			sum += ip;
			if (i==0)
				ser = ip;
		}
		double r = 1-sum;
		double mul = power(r,pw);
		printf("%.6lf\n", ((ser*(1-mul))/sum));
	}
	return 0;
}