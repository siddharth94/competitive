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

char mat[1005][1005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,m;
		get(n);
		get(m);

		F(i,n)
			scanf("%s",mat[i]);

		int tr = 0, br = 0, lc = 0, rc = 0;

		F(i,n)
		{
			bool r = false;
			F(j,m)
			{
				if (mat[i][j] == '*')
				{
					r = true;
					break;
				}
			}
			if (r)
			{
				tr = i;
				break;
			}
			else
			{
				tr = -1;
			}
		}

		if (tr == -1)
		{
			printf("0\n");
			continue;
		}

		FRE(i,n-1)
		{
			bool r = false;
			F(j,m)
			{
				if (mat[i][j] == '*')
				{
					r = true;
					break;
				}
			}
			if (r)
			{
				br = i;
				break;
			}
		}

		F(j,m)
		{
			bool c = false;
			F(i,n)
			{
				if (mat[i][j] == '*')
				{
					c = true;
					break;
				}
			}
			if (c)
			{
				lc = j;
				break;
			}
		}

		FRE(j,m-1)
		{
			bool c = false;
			F(i,n)
			{
				if (mat[i][j] == '*')
				{
					c = true;
					break;
				}
			}
			if (c)
			{
				rc = j;
				break;
			}
		}

		int size = max(br-tr+1, rc-lc+1);

		printf("%d\n", size/2 + 1);
	}
	return 0;
}