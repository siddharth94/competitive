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

string txt, pat;

LL mod1 = 1e9+7;
LL mod2 = 1e9+13;


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
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		cin >> txt >> pat;

		LL pat_hash1 = 0, pat_hash2 = 0;
		LL txt_hash1 = 0, txt_hash2 = 0;
		LL base = 31;

		int m = pat.length();
		int n = txt.length();

		LL pp1 = 1, pp2 = 1;

		for (int i=m-1; i>=0; i--)
		{
			pat_hash1 = (pat_hash1 + pat[i]*pp1)%mod1;
			pat_hash2 = (pat_hash2 + pat[i]*pp2)%mod2;

			txt_hash1 = (txt_hash1 + txt[i]*pp1)%mod1;
			txt_hash2 = (txt_hash2 + txt[i]*pp2)%mod2;

			if (i!=0)
			{
				pp1 = (pp1*base)%mod1;
				pp2 = (pp2*base)%mod2;
			}
		}

		vector <int> pos;

		if (pat_hash2 == txt_hash2 && pat_hash1 == txt_hash1)
			pos.pb(1);

		R(i,m,n)
		{
			txt_hash1 = ( (( (txt_hash1 - txt[i-m]*pp1)%mod1 + mod1) * base) + txt[i]) %mod1;
			txt_hash2 = ( (( (txt_hash2 - txt[i-m]*pp2)%mod2 + mod2) * base) + txt[i]) %mod2;

			if (txt_hash1 == pat_hash1 && txt_hash2 == pat_hash2)
			{
				pos.pb(i-m+2);
			}
		}

		if (pos.size())
		{
			printf("%lu\n", pos.size());

			F(i,pos.size())
				printf("%d ", pos[i]);
			printf("\n\n");
		}
		else
			printf("Not Found\n\n");
	}
	return 0;
}