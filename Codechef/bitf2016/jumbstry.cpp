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

struct BOX{
	LL l,b,h;
	LL base;

	BOX(LL lr, LL br, LL hr){
		l = lr;
		b = br;
		h = hr;
		base = lr*br;
	}	
};

typedef BOX box;

vector < box > bases;
LL dp[20000];

bool cmp(box a, box b) {
	return a.base > b.base;
}

int main()
{
	int n;
	get(n);

	LL l,b,h;

	F(i,n){
		getll(l), getll(b), getll(h);
		bases.pb(box(max(l,b),min(l,b),h));
		bases.pb(box(max(h,b),min(h,b),l));
		bases.pb(box(max(l,h),min(l,h),b));
	}

	sort(bases.begin(), bases.end(), cmp);

	int len = bases.size();
	
	F(i,len){
		dp[i] = bases[i].h;
	}

	LL ans = dp[0];
	F(i,len){
		F(j,i){
			if (bases[i].l < bases[j].l && bases[i].b < bases[j].b)
				dp[i] = max(dp[i], dp[j] + bases[i].h);
		}
		ans = max(ans, dp[i]);
	}

	printf("%lld\n", ans);
	return 0;
}