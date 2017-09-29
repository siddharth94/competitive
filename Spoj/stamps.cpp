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

int frnd[1005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		bool flag = true;
		printf("Scenario #%d:\n",__rep);
		int stamps,	n;
		get(stamps);
		get(n);
		F(i,n)
			get(frnd[i]);
		sort (frnd, frnd+n);
		LL sum = 0,count = 1;
		FRE(i,n-1)
		{
			sum += frnd[i];
			if (sum < stamps)
				count++;
			else
			{flag = false; break;}
		}
		if (flag)
			printf("impossible\n\n");
		else
			printf("%lld\n\n",count);
	}
	return 0;
}