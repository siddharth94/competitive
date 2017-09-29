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
#define get(Z) scanf("%lld",&Z);

int main()
{
	LL mod = 1e9+7;
	LL a,b;
	get(a);
	get(b);
	LL sig = (a*(a+1))>>1;
	sig %= mod;
	LL ct = 0,div;
	for (LL i=1; i<b; i++)
	{
		div= a*i % mod;
		// ct += ((div*i)%mod + b*(((div*(div+1))/2)%mod))%mod; 
		// ct %= mod;
		ct += ((((b*i)%mod)*sig) + (a*i))%mod;
		ct%= mod;
	}
	printf("%lld",ct);
	return 0;
}