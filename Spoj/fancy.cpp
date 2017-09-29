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


int main()
{
	int T;
	get(T);
	char a;
	register int dup=0, pr, ans=1;
	while (T--)
	{
		register char c[35];
		scanf("%s",c);
		register int k = strlen(c);
		
		// a = gc();
		// register char prev = 'a',curr;
		// while (a<'0' || a>'9') a=gc();
		// for (; a>='0' && a<='9'; a=gc())
		// {
		// 	curr = a;
		// 	if (prev==curr)
		// 		dup++;
		// 	pr = 1<<dup;
		// 	ans*=pr;
		// 	dup = 0;
		// 	prev = curr;
		// }
		// c[k] = '\0';

		F(i,k-1)
		{
			while (c[i] == c[i+1])
				dup++, i++;
			pr = 1<<dup;
			ans *= pr;
			dup = 0;
		}

		print(ans);
		ans = 1;
	}
	return 0;
}