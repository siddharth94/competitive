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

char s[100005];
char ans[100005];

int main()
{
	int n;
	get(n);
	scanf("%s",s);
	int j=0;

	F(i,n)
	{
		if (s[2*i] != 'A' && s[2*i+1] != 'A')
		{
			ans[j] = 'A';
			j++;
		}
		if (s[2*i] != 'B' && s[2*i+1] != 'B')
		{
			ans[j] = 'B';
			j++;
		}
		if (s[2*i] != 'C' && s[2*i+1] != 'C')
		{
			ans[j] = 'C';
			j++;
		}
		if (s[2*i] != 'D' && s[2*i+1] != 'D')
		{
			ans[j] = 'D';
			j++;
		}

		if (j-3>=0 && ans[j-2] == ans[j-3])
		{
			char c = ans[j-1];
			ans[j-1] = ans[j-2];
			ans[j-2] = c; 
		}
	}

	printf("%s\n", ans);
	return 0;
}