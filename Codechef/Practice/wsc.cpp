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

int lis[25][3];

int main()
{
  int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
	  int n,m;
	  get(n);
	  get(m);
	  F(i,m)
	  {
	    int x,y;
	    get(x);
	    get(y);
	    lis[i][0] = x;
	    lis[i][1] = y;
	  }
	  
	  if (n == 1 || n == 2)
	    printf("YES\n");
	  else if (n == 3 && m <= 2)
	    printf("YES\n");
	  else if (n >= 4 && m >= 3)
	    printf("NO\n");
	  else if (n >= 4 && m <= 1)
	    printf("YES\n");
	  else if (n >= 4)
	  {
	    if (lis[0][0] == lis[1][0] || lis[0][0] == lis[1][1] || lis[0][1] == lis[1][0] || lis[0][1] == lis[1][1])
	      printf("YES\n");
	    else printf("NO\n");
	  }
	  else printf("NO\n");
	}
	return 0;
}