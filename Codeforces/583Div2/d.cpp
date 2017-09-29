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

int a[105];

int main()
{
	int n,t;
	cin >> n >> t;
	int m = 0;
	int occ = 0;
	F(i,n)
	{
		cin >> a[i];
		if (a[i] == m)
			occ++;
		else if (a[i] > m)
		{
			occ = 1;
			m = a[i];
		}
	}
	int count = 0;
	int prev = 0;
	int ans = 0;
	int len = 0;
	while (count < t && prev != m)
	{
		F(i,n)
		{
			if (a[i] >= prev)
			{
				prev = a[i];
				len++;
			}
		}
		ans += len;
		count++;
	}
	int left = t-count;
	ans += left*occ;
	cout << ans;
	return 0;
}