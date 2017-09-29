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

int a[100005], p[100005];

int main()
{
	int n;
	cin >> n;
	F(i,n)
	{
		cin >> a[i] >> p[i];
	}
	R(i,1,n)
	{
		if (p[i] > p[i-1])
			p[i] = p[i-1];
	}
	LL ans = 0;
	F(i,n)
	{
		ans += p[i]*a[i];
	}
	cout << ans;
	return 0;
}