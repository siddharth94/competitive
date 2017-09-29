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

inline void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

LL a[100005];
LL power2[100005];
LL prod[100005]; // product upto ith element
LL inverse[100005];

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

int main()
{
	LL mod = 1000000007;
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		LL sum = 0ll;
		LL ans = 0ll;

		F(i,n)
		{
			getll(a[i]);
			
			if (i==0)
			{
				power2[i] = 1;
				prod[i] = a[i];
			}
			else
			{
				power2[i] = (2ll*power2[i-1])%mod;
				prod[i] = (a[i]*prod[i-1])%mod;
			}

			inverse[i] = power(a[i], mod-2, mod);
		}

		F(i,n)
		{
			if (i < n-1)
				sum = (sum + (prod[i]*power2[n-i-2]) % mod) % mod;
			else
				sum = (sum + prod[i]) % mod;
		}

		LL m = 0;
		ans = sum;
		LL left = 0;

		for (int i=0; i<n-1; i++)
		{
			sum = (sum - (a[i]*power2[n-i-2+m]) % mod ) % mod;
			while (sum < 0)
				sum += mod;

			sum = (sum*inverse[i]) % mod;

			if (left >= 1)
			{
				sum = (sum*2ll) % mod;
				m++;
			}
			left++;
			ans = (ans+sum) % mod;
		}

		printf("%lld\n", ans);

	}
	return 0;
}