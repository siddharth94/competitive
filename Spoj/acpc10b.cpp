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

pii found[1000];

int solve(int a, int b)
{
	int a1 = a;
	int b1 = b;
	memset(found,0,sizeof(found));
	int f = 1;

	if (a>998)
	{
		f = 2;
		int sum = 0;
		while (a!=0)
		{
			int d = a%10;
			sum += d*d;
			a/=10;
		}
		a = sum;
	}

	while (found[a].ft == 0)
	{
		found[a] = mp(f,1);
		f++;
		int sum = 0;
		while (a!=0)
		{
			int d = a%10;
			sum += d*d;
			a/=10;
		}
		a = sum;
	}

	int j = 1;

	if (b>998)
	{
		j = 2;
		int sum = 0;
		while (b!=0)
		{
			int d = b%10;
			sum += d*d;
			b/=10;
		}
		b = sum;
	}

	while (found[b].ft == 0)
	{
		found[b] = mp(j,2);
		j++;
		int sum = 0;
		while (b!=0)
		{
			int d = b%10;
			sum += d*d;
			b/=10;
		}
		b = sum;
	}

	if (a1 == b1)
		return 2;
	else if (found[b].sd == 1)
		return j+found[b].ft;
	else
		return 0;
}

int main()
{
	int a,b;
	get(a);
	get(b);

	while (a!=0 || b!=0)
	{		
		printf("%d %d %d\n", a,b,min(solve(a,b),solve(b,a)));

		get(a);
		get(b);
	}
	return 0;
}