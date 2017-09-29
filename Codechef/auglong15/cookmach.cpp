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

long long power[70];

int main()
{
	long long k = 1;
	F(i,63)
	{
		power[i] = k;
		k <<= 1;
	}
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int a,b;
		get(a);
		get(b);
		int ori, idx;
		ori = idx = (int)(log(a)/log(2));
		while (a != power[idx])
		{
			a/=2;
			if (a < power[idx])
				idx--;
		}
		int des = (int)(log(b)/log(2));
		int out = abs(des-idx);
		out += abs(ori-idx);
		printf("%d\n", out);
	}
	return 0;
}