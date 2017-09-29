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

int a[1000006];
int b[1000006];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;
		
		get(n);
		F(i,n)
			get(a[i]);
		
		get(m);
		F(j,m)
			get(b[j]);
		
		sort(a,a+n);
		sort(b,b+m);

		int i=0, j=0;
		int min_diff = 999999999;
		while (i<n && j<m)
		{
			if (a[i] < b[j])
			{
				min_diff = min(min_diff, b[j]-a[i]);
				i++;
			}
			else if (a[i] > b[j])
			{
				min_diff = min(min_diff, a[i]-b[j]);
				j++;
			}
			else
			{
				min_diff = 0;
				break;
			}
		}
		printf("%d\n", min_diff);
	}
	return 0;
}