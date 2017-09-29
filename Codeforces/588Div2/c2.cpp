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

int w[1000506];

int main()
{
	int n;
	cin >> n;
	int tmp;
	int m = -1;
	F(i,n)
	{
		cin >> tmp;
		w[tmp]++;
		m = max(tmp,m);
	}
	LL ans = 0;
	F(i,1000500)
	{
		if (w[i] == 0)
			continue;
		if (w[i]%2)
			ans++;
		w[i+1] += w[i]/2;
	}
	cout << ans;
	return 0;
}