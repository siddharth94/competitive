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
#define get(x) scanf("%d",&x)

pair <int,int> a[100005];

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}

int main()
{
	int n,d;
	get(n);
	get(d);

	F(i,n)
	{
		int x,y;
		get(x);
		get(y);
		a[i] = make_pair(x,y);
	}
	sort(a,a+n, cmp);
	
	int i=0, prev=0;
	LL frsum=0, maxsum=0;
	
	while(i<n)
	{
		while (i<n && a[i].first - a[prev].first < d)
		{
			frsum += (LL)(a[i].second);
			i++;
		}
		if (frsum > maxsum)
			maxsum = frsum;
		frsum -= a[prev].second;
		prev++;
	}
	printf("%lld\n", maxsum);

	return 0;
}