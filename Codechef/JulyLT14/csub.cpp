#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
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
		int n;
		LL q=0;
		// get(n);
		// string s;
		// cin >> s;
		// F(i,n)
		// 	if (s[i]=='1')
		// 		q++;
		// LL ans = q*(q+1)/2;
		// printf("%lld\n",ans);
		// int q=0;
		get(n);
		char c=gc();
		while (c!='1' && c!='0') c=gc();
		while ((c=='1' || c=='0') && n)
		{
			if (c=='1')
				q++;
			n--;
			c=gc();
		}
		LL l;
		if (!(q&1))
		{
			l=q>>1;
			l*=(q+1);
		}
		else
		{
			l=(q+1)>>1;
			l*=q;
		}
		printf("%lld\n",l);
	}
	return 0;
}