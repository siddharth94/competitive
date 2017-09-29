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
#define mp make_pair
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

int a[100005];
vector < pii > gifts;

int main()
{
	int n;
	get(n);
	F(i,n)
	{
		get(a[i]);
		gifts.pb(mp(a[i],i));
	}
	sort(gifts.begin(), gifts.end());
	n = gifts.size();
	LL max = -1e16;
	for (int i=n-1; i>=n-6 && i>=0; i--)
	{
		LL sum = (LL)gifts[i].ft;
		if (sum > max)
			max = sum;
		for (int j=i-1; j>=i-4 && j>=0; j--)
		{
			if (abs(gifts[j].sd - gifts[i].sd) == 1)
				continue;
			sum += (LL)gifts[j].ft;
			break;
		}
		if (sum > max)
			max = sum;
	}
	printf("%lld\n",max);
	return 0;
}