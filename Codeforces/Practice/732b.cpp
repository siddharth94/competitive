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
#define get(x) scanf("%d",&x);

int a[505];

int main()
{
	int n,k;
	get(n); get(k);

	F(i,n)
		get(a[i]);

	int ans = 0;

	F(i,n)
	{
		if (i==0)
			continue;
		ans += max(0, k-a[i]-a[i-1]);
		a[i] += max(0, k-a[i]-a[i-1]);
	}

	printf("%d\n", ans);
	F(i,n)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}