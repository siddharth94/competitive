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

int main()
{
	cout << "1000\n";
	F(i,1000)
	{
		cout << i+1 << endl;
	}
	return 0;
		cout << "200 200\n";
		F(j,200)
		{
			F(k,200)
			{
				int m = rand()%3;
				if (m==0)
					cout << "0";
				else if (m==1)
					cout << "T";
				else cout << "#";
			}
			cout << endl;
		}

	return 0;
}