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
		int n,k;
		int tmp;
		int count = 0;
		get(n);
		get(k);
		int c = n;

		while (n--)
		{
			get(tmp);
			if (!(tmp&1))
				count++;
		}		
		if (count == c && k==0)
			printf("NO\n");
		else if (count < c && k==0)
			printf("YES\n");
		else if (count >= k && k!=0)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}