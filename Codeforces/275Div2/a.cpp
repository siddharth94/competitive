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
#define getll(z) scanf("%lld",&z);



int main()
{
	LL l,r;
	getll(l);
	getll(r);
	if (l&1)
	{
		if (l+3 > r)
			printf("-1\n");
		else
			printf("%lld %lld %lld\n",l+1, l+2, l+3);
	}
	else
	{
		if (l+2 > r)
			printf("-1\n");
		else
			printf("%lld %lld %lld\n",l, l+1, 2+l);
	}
	// else printf("-1\n");
	return 0;
}