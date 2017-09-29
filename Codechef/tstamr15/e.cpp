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

#define NUM 1000005		// The number upto which primes are to be found.
vector <LL> prime;
int mark[NUM+2];

void sieve()
{
	memset(mark, false, sizeof(mark));
	for (LL i=2; i<=NUM; i++)
	{
		if (!mark[i])
		{
			prime.pb(i);
			for (LL j = i*i; j<=NUM; j+=i)
				mark[j] = true;
		}
	}
}

int myprime[200005];

int calc_prime(int a, int b)
{
	int sz = prime.size();
	int sq = b;
	F(j,sz)
	{
		if (prime[j] > sq)
			break;
		for (int k=a+(prime[j]-(a%prime[j]==0?prime[j]:a%prime[j])); k<=b; k+=prime[j])
			if (k != prime[j])
				myprime[k-a] = -1;
	}
	int ans = 0;
	F(i,b-a+1)
		if (myprime[i] != -1 && a+i!=1)
			ans++;
	return ans;

	// memset(myprime, 0, sizeof(myprime));
	// // int rt = sqrt(b);
	// F(i,prime.size())
	// {
	// 	if (prime[i]*prime[i] > b)
	// 		break;
	// 	int rem = (prime[i] - (a%prime[i])) % prime[i];
	// 	if (a+rem > b)
	// 		continue;
	// 	int next = a+rem;
	// 	if (a == prime[i])
	// 		next += prime[i];
	// 	while (next <= b)
	// 	{
	// 		myprime[next-a] = 1;
	// 		next += prime[i];
	// 	}
	// }
	// int ans = 0;
	// F(i,b-a+1)
	// {
	// 	if (myprime[i] == 0)
	// 		ans++;
	// }
	// return ans;
}

int highest_power(int base, int e, bool less=true)
{
	int h=0;
	int p=e;

	if (less)
	{
		while (p<base)
		{
			p = p*e;
			h++;
		}
		h++;
	}
	else
	{
		while (p<=base)
		{
			p = p*e;
			h++;
		}
	}
	return h;
}

int main()
{
	sieve();
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int a,b;
		LL ans = 0;
		get(a);
		get(b);
		int rt = sqrt(b);
		F(i,prime.size())
		{
			if (prime[i]*prime[i] > b)
				break;
			for (int q=1; q<prime.size(); q++)
			{
				if (prime[q] > 32)
					break;

				int pw = pow(prime[i], prime[q]-1);
				if (pw >= a && pw <= b)
					ans++;
			}

			// int k1 = highest_power(a,prime[i],true);
			// int k2 = highest_power(b,prime[i],false);
			// // if (k1 == 1)
			// // 	k1++;
			// if (k1 > k2)
			// 	continue;
			// k1++;
			// k2++;
			// vector<LL>::iterator low = lower_bound(prime.begin(), prime.end(), k1);
			// vector<LL>::iterator up = lower_bound(prime.begin(), prime.end(), k2);
			// if (k2 == *up)
			// 	up++;
			// ans += (LL)(up-low);
			// int answer=1, power=0;
			// while()

		}
		// cout << ans << "m" << endl;
		if (b < 999998)
		{
			vector <LL> :: iterator it = lower_bound(prime.begin(),prime.end(),a);
			vector <LL> :: iterator it2 = lower_bound(prime.begin(),prime.end(),b);

			if (*it2 == b)
				*it2++;

			ans += it2-it;
			
			// while (*it <= b)
			// {
			// 	ans++;
			// 	it++;
			// }
		}
		else
			ans += calc_prime(a, b);
		printf("%lld\n", ans);
	}
	return 0;
}