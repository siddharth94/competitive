#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
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

int main()
{
	cout << "100\n";
	F(i,100)
	{
		cout << "100000 100000\n";
		F(j,100000)
		{
			int m = rand()%2;
			if (!m)
			{
				int p = (rand()%100000)+1;
				int q = (rand()%100000)+1;
				int v = rand()%10000000;
				if (p>q) swap(p,q);
				cout << 0 << " " << p << " " << q << " " << v << endl;	
			}
			else
			{
				int p=(rand()%100000)+1;
				int q = (rand()%100000)+1;
				if (p>q) swap(p,q);
				cout << 1 <<" " << p << " " << q << endl;
			}
		}
		// cout << 1 << " " << 1 << " " << 100000 << endl;
	}
	return 0;
}