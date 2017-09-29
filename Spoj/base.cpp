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
	char num[8];
	while(scanf("%s",num) != EOF)
	{
		int from, to;
		get(from);
		get(to);
		int l = strlen(num);
		int dec = 0;
		int curr_pow = 1;
		for (int i=l-1; i>=0; i--)
		{
			int dig = num[i]-'0';
			if (num[i] >= 'A' && num[i] <= 'F')
				dig = num[i] - 'A' + 10;
			dec += curr_pow*dig;
			curr_pow *= from;
		}
		char ans[8];
		ans[7] = '\0';
		for (int i=6; i>=0; i--)
		{
			int dig = dec%to;
			ans[i] = dig + '0';
			if (dig > 9)
				ans[i] = dig + 'A' - 10;
			dec = dec/to;
		}
		if (dec > 0)
			printf("  ERROR\n");
		else
		{
			int o = 0;
			while (ans[o] == '0' && o<6)
				ans[o++] = ' ';
			printf("%s\n", ans);
		}
	}
	return 0;
}