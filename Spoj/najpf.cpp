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
#define endl '\n'

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
int table[1000005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		cin >> txt;
		cin >> pat;

		memset(table, 0, sizeof table);
		int j = 0, m = pat.length(), n = txt.length();

		R(i,1,m)
		{
			while (j>0 && pat[i] != pat[j])
				j = table[j-1];

			if (pat[i] == pat[j])
				table[i] = ++j;
		}

		j = 0;
		int cunt = 0;
		vector <int> pos;

		F(i,n)
		{
			while (j>0 && txt[i] != pat[j])
				j = table[j-1];

			if (txt[i] == pat[j])
			{
				j++;
				if (j==m)
				{
					cunt++;
					pos.pb(i-m+2);
					j = table[j-1];
				}
			}
		}

		if (cunt)
		{
			cout << cunt << endl;
			F(i,pos.size())
			{
				cout << pos[i] << " ";
			}
			cout << endl << endl;
		}
		else
			cout << "Not Found" << endl << endl;
		
		pos.clear();
	}
	return 0;
}