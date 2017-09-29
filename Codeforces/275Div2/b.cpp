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
#define get(z) scanf("%lld",&z)

int main()
{
	LL c1,c2,x,y;
	get(c1);
	get(c2);
	get(x);
	get(y);
	LL g = x*y;
	LL v = c1+c2;

	while (!(((v-(v/x)) >= c1) && ((v-(v/y)) >= c2) && ((v-(v/g)) >= c1+c2)))
		v = (c1+c2)<<1;

	LL u = v;
	LL l = u>>1;
	

	while (u-l > 1)
	{
		v = (u+l)>>1;

		if (((v-(v/x)) >= c1) && ((v-(v/y)) >= c2) && ((v-(v/g)) >= c1+c2))
			u = v;
		else l = v;
	}

	printf("%lld",u);

	// for (LL v=c1+c2;;v++)
	// {
	// 	if (((v-(v/x)) >= c1) && ((v-(v/y)) >= c2) && ((v-(v/g)) >= c1+c2))
	// 	{
	// 		printf("%lld\n",v);
	// 		return 0;
	// 	}
	// }
	return 0;
}