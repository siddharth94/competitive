#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
#define pii pair <int, int>
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

LL mod;
LL a[100005];

LL sum(LL n)
{
	LL m = 30*mod;
	// while (n >= m) n-=m;
	n %= m;
	LL n2 = n*n;
	// while (n2 >= m) n2-=m;
	n2 %= m;
	LL n3 = n2*n;
	n3 %= m;
	// while (n3 >= m) n3-=m;
	LL n4 = n3*n;
	n4 %= m;
	// while (n4 >= m) n4-=m;
	LL n5 = n4*n;
	n5 %= m;
	// while (n5 >= m) n5-=m;
	LL a = 6*n5, b = 15*n4, c = 10*n3, d = 30*n2, e = 31*n;
	a %= m;
	b %= m;
	c %= m;
	d %= m;
	e %= m;
	// while (a >= m) a-=m;	
	// while (b >= m) b-=m;	
	// while (c >= m) c-=m;	
	// while (d >= m) d-=m;	
	// while (e >= m) e-=m;
	LL ans = (a+b+c-n);
	while (ans < 0) ans+=m;
	ans %= m;
	// while (ans >= m) ans-=m;
	ans /= 30;	
	return ans;
}

// int a[100005];
// int p[10000];
// int factor[1000];

// void sieve()
// {
// 	int i=0;
// 	memset(a,0,sizeof(a));
// 	for (int j=2; j<100001; j++)
// 	{
// 		if (a[j] == 1)
// 			continue;
// 		else
// 		{
// 			p[i++] = j;
// 			cout << j << ","; 
// 			int k = 2;
// 			int pr = j*k;
// 			while (pr<=100000)
// 			{
// 				a[pr] = 1;
// 				pr = j*(++k);
// 			}
// 		}
// 	}
// 	return;
// }

// void factor(LL n)
// {

// }

int main()
{

	int T;
	get(T);
	while (T--)
	{
		LL n;
		getll(n);	
		getll(mod);
		// mod = 10000000001;

		// LL k = sum(n);
		// cout << k << endl;
		// continue;

		LL w = 0;
		LL s, i=1, prev=n, new_i, a_curr, a_prev=0, tmp, ans=0;
		LL sq = sqrt(n);
		while (i<=sq)
		{
			while (n/i == prev)
				i++;
			new_i = i-1;
			s = sum(new_i);
			a_curr = s - a_prev;
			while (a_curr < 0) a_curr += mod;
 			a_curr %= mod;
			tmp = prev*a_curr;
			// while (tmp >= mod) tmp-=mod;
			tmp %= mod;
			if (tmp < 0){
				printf("%lld %lld\n", i,tmp);
				// return 0;
			}
			ans += tmp;
			ans %= mod;
			// while (ans>=mod) ans-=mod;
			prev = n/i;
			a_prev = s;
			if (new_i == n/new_i)
				break;
			a[w++] = n/new_i;
		}

		--w;
		while (w>=0)
		{
			new_i = a[w--];
			s = sum(new_i);
			a_curr = s - a_prev;
			while (a_curr < 0) a_curr += mod;
			a_curr %= mod;
			tmp = (n/new_i)*a_curr;
			// while (tmp >= mod) tmp-=mod;
			tmp %= mod;
			ans += tmp;
			ans %= mod;
			// while (ans>=mod) ans-=mod;
			// prev = new_i+1;
			a_prev = s;
		}

		// printf("ans of %lld mod %lld : %lld\n",n,mod,ans);
		printf("%lld\n",ans);
		// sieve();
	}

	return 0;

	// sieve();
	// int T;
	// get(T);
	// while (T--)
	// {
	// 	LL n;
	// 	getll(n);
	// 	factor(n);

	// }	
	// return 0;
}

















