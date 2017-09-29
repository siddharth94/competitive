#include <bits/stdc++.h>
using namespace std;

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

int sq[40];
int ans[1005];

int main()
{
	int T;
	get(T);
	F(i,32)
		sq[i] = (i+1)*(i+1);
	F(i,1003)
		ans[i] = 10;
	ans[0] = 0;
	int count = 0;
	while (T--)
	{
		int a;
		get(a);
		if (a > count)
		{
			for (int i = count+1; i<=a; i++)
			{
				int j=0;
				while (i >= sq[j])
				{
					ans[i] = min(ans[i], ans[i-sq[j]]+1);
					j++;
				}
			}
			count = a;
		}
		printf("%d\n",ans[a]);
	}
	return 0;
}