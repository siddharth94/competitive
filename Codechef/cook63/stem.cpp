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

vector <string> words;
vector < vector <string> > substring;

void gen_substr()
{
	F(i,n)
	{
		vector <string> temp;
		F(a,words[i].length())
		{
			R(b,a,words[i].length())
			{
				temp.pb(words[i].substr(a,b-a+1));
			}
		}
		sort(temp.begin(), temp.end());
		substring.pb(temp);
	}
}

bool cmp(vector<string> a, vector<string> b)
{
	return a.size() < b.size();
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		int minlen;
		string minword;
		F(i,n)
		{
			char s[25];
			scanf("%s",s);
			string t(s);
			words.pb(t);
			if (t.length() < minlen)
			{
				minlen = t.length();
				minword = t;
			}
		}
		gen_substr();
		sort(substring.begin(), substring.end(), cmp);
		F(i,substring[0].size())
		{
			R(j,1,n)
			{
				
				
			}
		}
	}
	return 0;
}