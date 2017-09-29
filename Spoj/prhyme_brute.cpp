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

vector <string> dic;

int main()
{
	int i=0, j=0;
	while (1)
	{
		string s;
		getline (cin,s);
		if (s.length() == 0)
			break;
		dic.pb(s);
	}
	sort(dic.begin(), dic.end());
	while (1)
	{
		string s;
		cin >> s;
		if (s.length() == 0)
			break;
		int slen = s.length();
		int maxsize = -999999999;
		string maxmatch = "";
		F(i,dic.size())
		{
			if (dic[i] == s)
				continue;
			int dicsz = dic[i].length();
			int strsz = slen;
			while (dicsz>0 && strsz>0 && dic[i][dicsz-1] == s[strsz-1])
			{
				dicsz--;
				strsz--;
			}
			if (slen-strsz > maxsize)
			{
				maxmatch = dic[i];
				maxsize = slen-strsz;
			}
		}
		cout << maxmatch << endl;
	}
	return 0;
}