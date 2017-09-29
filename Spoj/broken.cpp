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

map <char,int> m;
string s;

int main()
{
	while (1)
	{
		int k;
		get(k);
		if (k==0)
			return 0;
		getline(cin,s);
		int l = s.length();
		int length = 0;
		register int i = 0;

		while (m.size() < k && i<l)
		{
			if (m.find(s[i]) == m.end())
			{
				m[s[i++]] = 1;
				length++;
			}
			else
			{
				m[s[i++]]++;
				length++;
			}
		}

		int max = length;
		int tmp,dec;
		for (;i<l;i++)
		{
			if (m.find(s[i]) == m.end())
			{
				m[s[i]] = 1;
				tmp = length;
				length += 1 - m[s[i-length]];
				dec = m[s[i-tmp]]--;
				for (register int j=1; j<dec; j++)
					m[s[i-tmp+j]]--;
				if (max<length) 
					max = length;
			}
			else
			{
				if (m[s[i]] > 0)
				{
					m[s[i]]++;
					length++;
					if (max<length) 
						max = length;
				}
				else
				{
					m[s[i]]++;
					tmp = length;
					length += m[s[i]] - m[s[i-length]];
					dec = m[s[i-tmp]]--;
					for (register int j=1; j<dec; j++)
						m[s[i-tmp+j]]--;
					if (max<length) 
						max = length;
				}
			}
		}
		printf("%d\n",max);
		m.clear();
	}
	return 0;
}