#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

char tmp[1004];
set<string> words;

void brk(string s)
{
	int prev = -1;
	size_t pos = s.find(" ");
	while (pos != string::npos)
	{
		if (prev+1 == pos)
		{
			prev = pos;
			pos = s.find(" ",prev+1);
		}
		else
		{
			string tmp="";
			for (int i=prev+1;i<prev+1+pos-prev;i++)
				tmp+=s[i];
			string tmpo = string(tmp);
			words.insert(tmpo);
			prev = pos;
			pos = s.find(" ",prev+1);
		}
	}
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		words.clear();
		string s;
		getline (cin,s);
		s+=" ";
		brk(s);
		cout << words.size() << endl;
	}
	return 0;
}