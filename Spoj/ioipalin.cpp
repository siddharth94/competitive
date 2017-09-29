#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
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

// int solve(char *s, char* rev, int n)
// {
// 	for (int i=0; i<=n; i++)
// 	{
// 		for (int j=0; j<=n; j++)
// 		{
// 			if (i==0 || j==0)
// 				lcs[i][j] = 0;
// 			else if (s[i-1] == rev[j-1])
// 				lcs[i][j] = 1 + lcs[i-1][j-1];
// 			else
// 				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
// 		}
// 	}
// 	return 0;
// }

	
	int lcs[5005][5005];
	char s[5005],rev[5005];

int main()
{
	int n;
	get(n);
	scanf("%s",s);

	F(i,n)
		rev[i] = s[n-i-1];

	rev[n] = '\0';

	// solve(s,rev,n);
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i==0 || j==0)
				lcs[i][j] = 0;
			else if (s[i-1] == rev[j-1])
				lcs[i][j] = 1 + lcs[i-1][j-1];
			else
				lcs[i][j] = (lcs[i-1][j] > lcs[i][j-1]) ? lcs[i-1][j] : lcs[i][j-1];
		}
	}

	printf("%d\n",n-lcs[n][n]);

	return 0;
}