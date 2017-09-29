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

char s[5005];
LL one[5005], two[5005];

int main()
{
	while(1)
	{
		scanf("%s",s);
		if (s[0] == '0')
			break;
		int n = strlen(s);
		for (int i=0; i<n; i++)
		{
			if (i==0)
			{
				one[i] = 1;
				two[i] = 0;
			}
			else if (i==1)
			{
				if (s[i] != '0')
					one[i] = one[i-1];
				else one[i] = 0;
				if (((s[i]-'0')+(s[i-1]-'0')*10) <= 26)
					two[i] = one[i-1];
				else two[i] = 0;
			}
			else
			{
				if (s[i] != '0')
					one[i] = one[i-1] + two[i-1];
				else one[i] = 0;
				if ( ((s[i]-'0') + (s[i-1]-'0')*10) <= 26 && s[i-1] != '0')
					two[i] = one[i-2] + two[i-2];
				else two[i] = 0;
			}
		}
		printf("%lld\n",one[n-1]+two[n-1]);
	}
	return 0;
}