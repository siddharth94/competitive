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

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int c;
		get(c);

		LL l,r;
		r = 1.05*c;
		l = ceil(0.95*c);

		string s = to_string(c);
		int n = s.size()-1;
		string tmp;
		
		while (s[n] == '0')
			n--;

		bool ans = true;

		if (s[n] != '5')
		{
			s[n] = '5';
			int k = atoi(s.c_str());
			if (k<=r && k>=l)
				ans = false;
		}

		if (ans)
		{
			s[n] = '0';
			int k = atoi(s.c_str());
			if (k<=r && k>=l)
				ans = false;


			if (ans)
			{
				n--;
				while (n>=0 && s[n] == '9')
				{
					s[n] = '0';
					n--;
				}
				if (n<0)
				{
					tmp = '1' + s;
					k = atoi(tmp.c_str()); 
				}
				else
				{
					s[n]++;
					k = atoi(s.c_str());
				}
				if (k>=l && k<=r)
					ans = false;
			}
		}

		if (ans)
			printf("not absurd\n");
		else
			printf("absurd\n");
	}
	return 0;
}