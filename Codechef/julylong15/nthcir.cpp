#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(long long i=a;i<=b;i++)
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

LL n[10000007];
double r[10000007];

int main()
{
	int t;
	get(t);
	
	LL p,m,b;
	getll(n[0]);
	getll(p);
	getll(m);
	getll(b);

	scanf("%lf", &r[1]);
	scanf("%lf", &r[2]);
	scanf("%lf", &r[3]);
	scanf("%lf", &r[4]);

	double ans = 0;
	double sum = (1/r[2]) - (1/r[1]);
	double prod = ((-1)/r[1])*(1/r[2]);

	LL max_n = 0;

	RE(i,1,t)
	{
		n[i] = (n[i-1]*p)%m + b;
		max_n = max(max_n, n[i]);
	}

	RE(i,5,max_n)
	{
		double pairsum = prod + (1/r[i-1])*sum;
		double nsum = sum + (1/r[i-1]);
		if (i==5){
			double tmp;
			tmp = nsum + 2*sqrt(pairsum);
			if (tmp-r[3] > 0.001) 
				tmp = nsum - 2*sqrt(pairsum);
			r[i] = tmp;
		}
		r[i] = max(nsum + 2*sqrt(pairsum), nsum - 2*sqrt(pairsum));
		r[i] = (1/r[i]);
	}

	RE(i,1,t)
	{
		ans += r[n[i]];
	}

	printf("%.6lf\n", ans);
	return 0;
}