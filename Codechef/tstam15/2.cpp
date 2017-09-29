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

int a[20005];

int main()
{
	string s;
	cin >> s;

	int len = s.length();

	F(i,len)
		a[i] = s[i] - '0';

	int q;
	get(q);

	F(i,q)
	{
		int m,l;
		get(m);
		get(l);

		LL ans = 0;

		F(i,len)
		{
			int prev = 0;
			
			R(j,i,len)
			{
				prev = ((prev*10)%m + a[j]%m)%m;
				if (prev == l)
				{
					cout << i << " " << j << endl;
					ans++;
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}