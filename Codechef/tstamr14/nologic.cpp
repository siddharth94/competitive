#include <bits/stdc++.h>
using namespace std;

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

int main()
{
	int T;
	get(T);
	while (T--)
	{
		string s;
		char a[45];
		getline(std::cin,s);

		F(i,26)
			a[i] = 'a'+i;
		a[26] = '\0';

		int len = s.length();

		F(i,len)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] - 'A' + 'a';
			}
			if (s[i] >= 'a' && s[i] <= 'z')
				a[s[i] - 'a'] = ' ';
		}

		if (strcmp(a,"                          ") != 0)
			printf("%s\n",a);
		else printf("~\n");
	}
	return 0;
}