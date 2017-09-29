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

string s;
int ans;

bool check(int ss, int se)
{
	char c = s[ss];
	R(i,ss,se)
	{
		if (s[i] != c)
			return false;
	}
	return true;
}

bool bin_search(int ss, int se, int level)
{
	if ((ss-se)%2 == 0)
	{
		int mid = (ss+se)>>1;
		bool l = bin_search(ss, mid, level+1);
		bool r = bin_search(mid, se, level+1);
		if (l && r && s[ss] == s[mid])
		{
			if (ans > level)
				ans = level;
			return true;
		}
	}
	else
	{
		if (check(ss,se))
		{
			if (ans > level)
				ans = level;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		cin >> s;
		ans = 50;
		bin_search(0, s.length(), 0);	
		printf("%d\n", ans==50?-1:ans);
	}
	return 0;
}