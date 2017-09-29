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
	int T;
	get(T);
	while (T--)
	{
		int x,y;
		get(x);
		get(y);
		bool flag = false;
		if ((x>0 && x&1) || (x<=0 && !(x&1)) || (!(y&1)))
		{
			if (x>0 && x&1) 
			{
				if (y>=0 && (y<=x+1))
						{printf("YES\n");
				flag = true;}
				else if (y<0 && (y>=1-x))
						{printf("YES\n");
				flag = true;}
				// else printf("NO\n");
			}
			if (x<0 && !(x&1))
			{
				if (y<=(-x) && y>=(x))
				if (!flag)
					if (!flag)
						{printf("YES\n");
				flag = true;}
				// else printf("NO\n");
			}
			if (x==0 && (!(y&1)))
			{
				if (!flag){
					printf("YES\n");
				flag = true;}
			}
			if (y>0 && (!(y&1)))
			{
				if (x>0 && (x<=y-1))
					{if (!flag)
						{printf("YES\n");
				flag = true;}
				}else if (x<0 && (x>=(-y)))
					{if (!flag)
						{printf("YES\n");
				flag = true;}
				}
				// else printf("NO\n");
			}
			if (y<0 && (!(y&1)))
			{
				if (x>0 && (x<=1-y))
				{
					if (!flag)
						{printf("YES\n");
				flag = true;}
				}else if (x<0 && (x>=y))
					{if (!flag)
						{printf("YES\n");
				flag = true;}
				}
				// else printf("NO\n");
			}
			if (!flag) printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}

// 1-3+5-7+9-11+13-15+17-19
// 2-4+6-8+10-12+14-16+18-20