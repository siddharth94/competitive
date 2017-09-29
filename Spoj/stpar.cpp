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

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

stack < LL > side;

int main()
{
	while (true)
	{
		LL n,x;
		getll(n);
		if (n == 0)
			break;
		
		LL curr = 0;

		F(i,n)
		{
			getll(x);
			if (x == curr+1)
			{
				curr = x;
				while (!side.empty() && side.top() == curr+1)
				{
					side.pop();
					curr += 1;
				}
			}
			else
			{
				side.push(x);
			}
		}
		while (!side.empty() && side.top() == curr+1)
		{
			side.pop();
			curr += 1;
		}
		if (side.empty())
			printf("yes\n");
		else
			printf("no\n");
		while (!side.empty())
			side.pop();
	}
	return 0;
}