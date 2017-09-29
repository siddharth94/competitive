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

vector <LL> squares;
vector <int> all;
bool mark[5000006];

void precompute()
{
	LL n = 5000001;
	for (LL i=1; i*i<n; i++)
	{
		squares.pb(i*i);
	}
	
	int k = squares.size();
	F(i,k)
	{
		R(j,i+1,k)
		{
			LL t = squares[i] + squares[j];
			if (t < n && !mark[t])
			{
				int ink = t;
				while (ink < 5000001)
				{
					if (!mark[ink])
					{	
						mark[ink] = true;
						all.pb(ink);
					}
					ink += t;
				}
			}
		}
	}
	sort(all.begin(), all.end());
}

int main()
{
	precompute();
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		vector <int>::iterator it = lower_bound(all.begin(), all.end(), n);
		if (*it == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}