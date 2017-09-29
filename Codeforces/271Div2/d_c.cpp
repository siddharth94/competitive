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

LL a[100005];
LL b[100005];
int sol[100005];
LL apowp[100005];
LL fact[100005];
LL modularfact[100005];
const LL mod = 1000000007;

LL power (LL b, LL p, LL mod)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	LL p1 = p,ans=1;
	if (p%2 == 0)
	{
		ans = power(b,p/2,mod)%mod;
		ans = (ans * ans)%mod;
	}
	else if (p%2 == 1)
	{
		ans = power (b,p/2,mod)%mod;
		ans = (((ans * ans) %mod) *b)%mod;
	}
	return ans;
}

void modulo(LL u)
{
	apowp[0] = 0;
	apowp[1] = 1;
	for (LL i=2; i<=u; i++)
		apowp[i] = power(i,mod-2,mod);
	return;
}

void facto(LL u)
{
	fact[0] = fact[1] = 1;
	modularfact[0] = 1;
	modularfact[1] = 1;
	for (LL i=2; i<=u; i++)
	{
		fact[i] = (fact[i-1] * i)%mod;
		modularfact[i] = (modularfact[i-1]*apowp[i])%mod;
	}
	return;
}

void update(LL i, LL val, LL u)
{
	for (LL j=i; j<=u; j+=(j&-j))
	{
		sol[j] += val;
		while (sol[j] >= mod)
			sol[j]-=mod;
		if (j==0)
			break;
	}
	return;
}

LL query(LL i)
{
	LL ans=0;
	for (LL j=i; j>=0; j-=(j&-j))
	{
		ans += sol[j];
		while (ans>=mod)
			ans-=mod;
		if (j==0)
			break;
	}
	return ans;
}

void solve(int k, LL u)
{
	LL tot, ans;
	for (LL i=1; i<=u; i++)
	{
		for(LL j=0; j*k <= i; j++)
		{
			tot = i-(j*k)+j;
			ans = ((((fact[tot]*modularfact[j]) %mod) * modularfact[tot-j]) %mod);
			update(i,ans,u);
		}
	}
}

int main()
{
	LL max = 0,a_tmp,b_tmp;
	int t,k;
	get(t);
	get(k);

	F(i,t)
	{
		scanf("%lld %lld", &a_tmp, &b_tmp);
		if (b_tmp>max)
			max = b_tmp;
		a[i] = a_tmp;
		b[i] = b_tmp;
	}

	memset(sol, 0, sizeof(sol));
	modulo(max);
	facto(max);
	solve(k,max);

	F(i,t)
	{
		LL ans1 = query(a[i]-1)%mod;
		LL ans2 = query(b[i])%mod;
		LL ans = (ans2-ans1)%mod;
		while (ans < 0)
			ans+=mod;
		printf("%lld\n", ans);
	}

	return 0;
}