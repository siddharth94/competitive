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

vector <bool> arr ((1ll << 31ll) + 5ll);
LL mod = 1ll<<32ll;

int main()
{
	LL q,s1,a,b;
	getll(q);
	getll(s1);
	getll(a);
	getll(b);

	LL ans = 0;
	LL num = s1>>1;

	if (s1 & 1)
	{
		arr[num] = true;
		ans = num;
	}

	for (int i=1; i<q; i++)
	{
		s1 = a*s1 + b;
		if (s1 > mod)
			s1 %= mod;

		num = s1>>1;

		if (s1 & 1)
		{
			if (!arr[num])
			{
				arr[num] = true;
				ans += num;
			}
		}
		else
		{
			if (arr[num])
			{
				arr[num] = false;
				ans -= num;
			}
		}
	}

	printf("%lld\n", ans);
	return 0;
}