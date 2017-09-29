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

char s[1000005], t[1000005];
int lps[1000005];
int lar;

void prefix(int m)
{
	int i = 1;
	int j = 0;
	lps[0] = 0;

	while (i<m)
	{
		if (s[i] == s[j])
			lps[i++] = ++j;
		else if (j != 0)
			j = lps[j-1];
		else
			lps[i++] = 0;
	}
}

bool check(int l, int st)
{
	R(i,st,l)
	{
		if (s[i] != t[i-st])
			return false;
	}
	return true;
}

bool kmp(int p, int l)
{
	int i = 0;
	int j = 0; // pattern (s)
	bool f = false;
	while (i<l)
	{
		if (s[j] == t[i])
			i++, j++;

		if (j > p)
		{
			if (check(i,p+1))
			{
				lar = max(lar, i);
				f = true;
			}
			j = lps[j-1];
		}
		else if (i<l && s[j] != t[i])
		{
			if (j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
	if (f) return true;
	return false;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		lar = 0;
		scanf("%s",s);
		scanf("%s",t);
		int l = strlen(s);
		prefix(l);

		int b = 0;
		int e = l-1;
		while (e>b)
		{
			int mid = (e+b)>>1;
			if (kmp(mid, l))
				b = mid+1;
			else
				e = mid;
		}
		printf("Case %d: %d\n", __rep, lar);
	}
	return 0;
}