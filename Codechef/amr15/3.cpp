#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(long long i=a;i>=b;i--)
#define F(i,n) for(long long  i=0;i<n;i++)
#define FE(i,n) for(long long i=0;i<=n;i++)
#define FR(i,n) for(long long i=n;i>0;i--)
#define FRE(i,n) for(long long i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <long long, long long>
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

#define NUM 100000		// The number upto which primes are to be found.
vector < pair <LL,LL> > fact[NUM+5];
LL mark[NUM+5];
LL num[NUM+5];

LL mod = 1e9+7;

void sieve()
{
	F(i,NUM+1)
		num[i] = i;
	memset(mark, false, sizeof(mark));
	for (LL i=2; i<=NUM; i++)
	{
		if (!mark[i])
		{
			for (LL j = i; j<i*i && j<=NUM; j+=i)
			{
				fact[j].pb(mp(i,1));
				num[j] /= i;
			}

			for (LL j = i*i; j<=NUM; j+=i)
			{
				mark[j] = true;
				LL p = 0;
				while (num[j]%i == 0)
				{
					p++;
					num[j] /= i;
				}
				fact[j].pb(mp(i,p));
			}
		}
	}
}

int pow2[100005];
LL modp = 1e9+6;

void calc_pow()
{
	LL p = 1;
	F(i,100002)
	{
		pow2[i] = p;
		p = (p*2)%modp;
	}
}

vector <LL> V, V2;

bool cmp( pii a, LL val)
{
	if (a.ft < val)
		return true;
	else return false;
}

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

LL calc_series(vector <LL> temp)
{
	sort(temp.begin(), temp.end());
	LL m = temp.size();
	LL ans = 0;
	F(i,m)
		ans += (temp[i]*pow2[m-1-i]);
	return ans;
}

int main()
{
	sieve();
	calc_pow();
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		int t;
		get(n);
		F(i,n)
		{
			get(t);
			if (t != 1)		
				V.pb(t);
		}
		LL ans = 1;
		bool flag = true;
		while (V.size() || V2.size())
		{	
			if (flag)
			{
				flag = !flag;
				if(V.size())
				{
					LL p1 = fact[V[0]][0].ft;
					vector <LL> temp;
					R(i,0,V.size())
					{
						vector < pii > :: iterator it = lower_bound(fact[V[i]].begin(), fact[V[i]].end(), p1, cmp);
						pii l = *it;
						if (l.ft == p1)
						{
							temp.pb(l.sd);
							V[i] /= power(p1,l.sd,mod);
						}
						if (V[i] != 1)
							V2.pb(V[i]);
					}
					LL part = calc_series(temp);
					ans *= power(p1, part, mod);
					ans %= mod;
					// V = V2;
					V.clear();
				}
			}
			else
			{
				flag = !flag;
				if(V2.size())
				{
					LL p1 = fact[V2[0]][0].ft;
					vector <LL> temp;
					R(i,0,V2.size())
					{
						vector < pii > :: iterator it = lower_bound(fact[V2[i]].begin(), fact[V2[i]].end(), p1, cmp);
						pii l = *it;
						if (l.ft == p1)
						{
							temp.pb(l.sd);
							V2[i] /= power(p1,l.sd,mod);
						}
						if (V2[i] != 1)
							V.pb(V2[i]);
					}
					LL part = calc_series(temp);
					ans *= power(p1, part, mod);
					ans %= mod;
					V2.clear();
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}