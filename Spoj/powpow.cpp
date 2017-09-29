#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long 

int get()
{
	char c=getchar();
	int x=0,flag=0;
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-')
	{
		flag=1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return flag?(-x):x;
}

LL base;
LL na[100005];

LL power_mod (int b, int p, int mod)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	LL ans=1;
	if (p%2 == 0)
	{
		ans = power_mod(b,p/2,mod)%mod;
		ans = (ans * ans)%mod;
	}
	else if (p%2 == 1)
	{
		ans = power_mod (b,p/2,mod)%mod;
		ans = (((ans * ans) %mod) *b)%mod;
	}
	return ans;
}

LL comb (int n, int r, int mod)
{
	int j=0;
	LL ans=1;
	while ((j++)<r)
		ans = (ans * (n--)) % mod;
	while ((j--)>2)
		ans = (ans * (power_mod(j,1000000005,mod) % mod) % mod);
	base = ans;
	na[r] = ans;
	return ans;
}

LL power (int n, int r, int mod, int b)
{
	if (b == 0)
		return 1;
	else if (b==1)
	{
		if (na[r] == 0)
			return comb(n,r,mod);
		else return na[r];
	}
	LL ans;
	ans = power(n,r,mod,b/2);
	if (b%2 == 0)
		return (ans * ans) % mod;
	else
		return ((((ans * ans) % mod) * base) % mod);
}

int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	int T = get();
	while (T--)
	{
		int a,b,n;
		a = get();
		b = get();
		n = get();
		LL ex = power(2*n,n,1000000007,b);
		printf("%lld\n",power_mod(a,ex,1000000007));
	}
	return 0;
}