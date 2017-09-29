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

string s;
int dp[20004][20004];

int main()
{
	cin >> s;
	int n = s.size();
	int q,m,l;
	get(q);
	F(z,q)
	{
		get(m);
		get(l);
		int count = 0;
		FE(i,n) {dp[0][i] = 0;}
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<n-i+1; j++)
			{
				dp[i][j] = ((dp[i-1][j] * 10%m)%m + ((int)(s[j+i-1]-'0'))%m)%m;
				if (dp[i][j] == l)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}