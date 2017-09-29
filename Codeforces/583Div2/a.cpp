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


int x[60],y[60];

int main()
{
	int n;
	cin >> n;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	int sq = n*n;
	F(i,sq)
	{
		int a,b;
		cin >> a >> b;
		if (x[a] == 0 && y[b] == 0)
		{
			x[a] = 1;
			y[b] = 1;
			cout << i+1 << " ";
		}
	}
	return 0;
}