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

char mat[205][205];
LL dp[205][205];
int m,n;

LL maxwoods(int i, int j)
{
	if (dp[i][j] == -1)
	{
		if (mat[i][j] == '#')
			return dp[i][j] = 0;

		LL down = 0,same = 0;
		if (i%2 && j>0)
			same = maxwoods(i,j-1);
		else if (!(i%2) && j<n-1)
			same = maxwoods(i,j+1);

		if (i<m-1)
			down = maxwoods(i+1,j);

		dp [i][j] = max(down,same);
		if (mat[i][j] == 'T')
			dp[i][j]++;
	}
	return dp[i][j];
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		cin >> m >> n;
		F(i,m)
		{
			string s;
			cin >> s;
			// cout << s << " string\n"; 
			F(j,n)
			{
				mat[i][j] = s[j];
			}
		}
		memset(dp, -1, sizeof(dp));
		LL ans = maxwoods(0,0);
		cout << ans << endl;
	}
	return 0;
}

// LL same = 0, up = 0;
// if (i%2 && i<n-1 && mat[i+1][j] != '#')
// 	same = maxwoods(i+1,j);
// else if (!(i%2) && i>0 && mat[i-1][j] != '#')
// 	same = maxwoods(i-1,j);
// if (j>0 && mat[i][j-1] != '#')
// 	up = maxwoods(i,j-1);
// dp[i][j] = max(up,same);
// if (dp[i][j] !=)