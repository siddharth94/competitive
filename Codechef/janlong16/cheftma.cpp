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

int a[100005];
int b[200005];

bool cmp(int one, int two)
{
	return one>two;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m,k;
		get(n);	
		get(k);
		get(m);	

		F(i,n)
		{
			get(a[i]);
		}	

		int c;
		LL sum = 0;
		F(i,n)
		{
			get(c);
			a[i] -= c;
			sum += a[i];
		}

		F(i,k)
			get(b[i]);

		F(i,m)
			get(b[k+i]);

		sort(a,a+n,cmp);
		sort(b,b+k+m,cmp);

		int i=0, j=0;

		while (i<n && j<m+k)
		{
			if (a[i] < b[j])
			{
				j++;
				continue;
			}
			if (b[j] <= a[i])
			{
				sum -= b[j];
				j++;
				i++;
				continue;
			}
		}

		printf("%lld\n", sum);
	}
	return 0;
}