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

int main()
{
	int T;
	get(T);
	while (T--)
	{
		bool flag = true;
		// cout << "a\n";
		LL s,e;	
		getll(s);
		getll(e);
		LL n,x,y;
		getll(n);
		F(i,n)
		{
			getll(x);
			getll(y);

			if ((x<=s && y>s) || (x<e && y>=e) || (x>s && x<e))
			{
				flag = false;
				printf("NO\n");
			}	 



			// if ((x > s && x < e) || (y>s && y<e) || (x<=s && y>=e))
			// {
			// 	flag = false;
			// 	printf("NO\n");
			// }
		}
		if (flag)
			printf("YES\n");
	}
	return 0;
}