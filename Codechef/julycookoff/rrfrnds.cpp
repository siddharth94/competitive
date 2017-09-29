#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(register int i=0;i<n;i++)
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

inline void print(int n)
{
	register int a1,a2,a3,a4,a5,a6,a7,a8,a9,r;
	r=n;
	a1 = r%10;
	r/=10;
	if (r!=0)
	{
		a2 = r%10;
		r/=10;
		if (r!=0)
		{
			a3 = r%10;
			r/=10;
			if (r!=0)
			{
				a4 = r%10;
				r/=10;
				if (r!=0)
				{
					a5 = r%10;
					r/=10;
					if (r!=0)
					{
						a6 = r%10;
						r/=10;
						if (r!=0)
						{
							a7 = r%10;
							r/=10;
							if (r!=0)
							{
								a8 = r%10;
								r/=10;
								if (r!=0)
									pc(r+'0');
								pc(a8+'0');
							}
							pc(a7+'0');
						}
						pc(a6+'0');
					}
					pc(a5+'0');
				}
				pc(a4+'0');
			}
			pc(a3+'0');
		}
		pc(a2+'0');
	}
	pc(a1+'0');
	pc('\n');
}

int network[2005][2005];
int suggest[2005][2005];

int bsf(register int n, register int i, register int level, register int parent = 0)
{
	register int count = 0;
	if (level == 1)
	{
		F(j,n)
		{
			if (network[i][j] == 1 && network[parent][j] != 1 && suggest[parent][j] != 1 && j != parent)
			{
				suggest[parent][j] = 1;
				count++;
			}
		}
		return count;
	}
	else
	{
		F(j,n)
		{
			if (network[i][j] == 1)
				count += bsf(n,j,1,i);
		}
		return count;
	}
}

int main()
{
	register int n;
	get(n);
	F(i,n)
		F(j,n)
		{
			register int c = gc();
			while (c!='0' && c!='1') c=gc();
			c -= '0';
			network[i][j] = c;
		}
	register int count = 0;
	F(i,n)
	{
		count += bsf(n,i,0);
	}
	print(count);
	return 0;
}