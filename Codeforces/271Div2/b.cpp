#include <bits/stdc++.h>
using namespace std;

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
#define get(n) scanf("%d",&n)

int a[100005];

int main()
{
	int n;
	get(n);

	F(i,n)
	{
		get(a[i]);
		if (i>0)
			a[i] += a[i-1];
	}

	int m;
	get(m);

	int *pt,q;

	F(i,m)
	{
		get(q);
		pt = lower_bound(a,a+n,q);
		printf("%ld\n",pt-a+1);
	}
	return 0;
}