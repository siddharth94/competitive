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
		char cube[10][20];
		F(i,6) 
		{
			scanf("%s", cube[i]);
		}
		bool poss = false;

		for (int i=2; i<6; i++)
		{
			if (cube[0][0] == cube[i][0] && cube[0][2] == cube[i][2])
			{
				for (int j=((i+2)/2)*2 ; j<6; j++)
				{
					if (cube[i][0] == cube[j][0] && cube[i][2] == cube[j][2])
					{
						poss = true;
					}
				}
			}
			if (cube[1][0] == cube[i][0] && cube[1][2] == cube[i][2])
			{
				for (int j=((i+2)/2)*2 ; j<6; j++)
				{
					if (cube[i][0] == cube[j][0] && cube[i][2] == cube[j][2])
					{
						poss = true;
					}
				}
			}
		}
		if (poss) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}