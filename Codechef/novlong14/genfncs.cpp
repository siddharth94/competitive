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
	cout << "100000" << endl;

	F(i,100000)
		cout << (rand()%(int)1e9)+1 << " ";

	F(i,100000)
	{
		int l = rand()%99999;
		l++;
		int k = 1e5 - l;
		int r = rand() % k;
		r++;
		cout << l << " " << l+r << endl;
	}

	cout << "100000" << endl;

	F(i,100000)
	{
		int r = rand()%2;
		if (r)
		{
			cout << "1 ";
			int x = rand()%100000;
			x++;
			int y = rand()%(int)1e9;
			y++;
			cout << x << " " << y << endl;
		}
		else
		{
			cout << "2 ";
			int m = rand()%99999;
			m++;
			int k = 1e5 - m;
			int n = rand() % k;		
			n++;
			cout << m << " " << m+n << endl;
		}
	}
	
	return 0;
}