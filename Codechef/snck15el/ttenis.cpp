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

char s[105];

int main()
{	
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		scanf("%s", s);
		int n = strlen(s);
		int win = 0;
		int chef = 0, opp = 0 ;
		for (int i=0; i<n; i++)
		{
			if (s[i] == '0')
				opp++;
			else chef++;
			if (chef > 10 && opp < 10)
			{
				win = 1;
				break;
			}
			if (chef < 10 && opp > 10)
			{
				win = -1;
				break;
			} 
			if (chef >= 10 && opp >= 10)
			{
				if (chef-opp >= 2)
				{
					win = 1;
					break;
				}
				else if (opp-chef >= 2)
				{
					win = -1;
					break;
				}
			}
		}
		if (win == 1)
			printf("WIN\n");
		else if (win == -1)
			printf("LOSE\n");
	}
	return 0;
}