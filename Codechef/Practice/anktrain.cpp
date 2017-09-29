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
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		int r = n%8;
		int ans;

		if (r==1 || r==2 || r==3)
			ans = n+3;
		else if (r==4 || r==5 || r==6)
			ans = n-3;
		else if (r==7)
			ans = n+1;
		else
			ans = n-1;

		printf("%d", ans);

		if (r == 1 || r == 4)
			printf("LB\n");
		else if (r == 2 || r == 5)
			printf("MB\n");
		else if (r==3 || r==6)
			printf("UB\n");
		else if (r==7)
			printf("SU\n");
		else
			printf("SL\n");
	}
	return 0;
}