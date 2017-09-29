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
	int m = 0;
	R(i,1,10000000)
	{
		vector<int> k;
		k.pb(i);
		int a = i;

		while (a!=89 && a!=1)
		{
			int sum = 0;
			while (a!=0)
			{
				int d = a%10;
				a/=10;
				sum += d*d; 
			}
			k.pb(sum);
			a = sum;
			if (k.size() > 10000)
				break;
		}

		// cout << i << " " << k.size() << endl;
		m = max(m,(int)k.size());
		k.clear();
	}
	cout << m << endl;
	return 0;
}