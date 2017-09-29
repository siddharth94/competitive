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

int a[1000005], b[1000005];
int lcs[2][1000005];

int main()
{
	memset(lcs,0,sizeof(lcs));
	int n;
	get(n);

	F(i,n)
	{
		get(a[i]);
		b[i] = a[i];
	}

	sort (b, b+n);
	bool flag = true;

	F(i,n)
	{	
		F(j,n)
		{
			// if (j==0 || i==0)
			// 	continue;
			if (flag)
			{
				if (a[i] == b[j])
					lcs[0][j] = (j>0?lcs[1][j-1]:0) + 1;
				else
					lcs[0][j] = max(lcs[1][j],(j>0?lcs[0][j-1]:0));
			}
			else
			{
				if (a[i] == b[j])
					lcs[1][j] = (j>0?lcs[0][j-1]:0) + 1;
				else
					lcs[1][j] = max(lcs[0][j],(j>0?lcs[1][j-1]:0));
			}
		}
		flag = !flag;
	}

	cout << n-max(lcs[1][n-1], lcs[0][n-1]) << endl;
	return 0;
}