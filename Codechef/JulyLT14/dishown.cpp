#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
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
	register int a1,a2,a3,a4,a5,r;
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
					pc(r+'0');
				pc(a4+'0');
			}
			pc(a3+'0');
		}
		pc(a2+'0');
	}
	pc(a1+'0');
	pc('\n');
}

int points[10005];
int neighbour[10005];

int big_neighbour(int x)
{
	if (neighbour[x] == x)
		return x;
	else
	{
		int j = big_neighbour(neighbour[x]);
		neighbour[x] = j;
		return j;
	}
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n;
		get(n);
		F(i,n)
		{
			neighbour[i] = i;
			get(points[i]);
		}
		int q;
		get(q);
		while (q--)
		{
			int code;
			get(code);
			if (code == 0)
			{
				int x,y;
				get(x);
				get(y);
				x--;
				y--;

				x = big_neighbour(x);
				y = big_neighbour(y);

				if (x == y)
				{
					pc('I'); pc('n'); pc('v'); pc('a');	pc('l'); pc('i'); pc('d'); pc(' '); pc('q'); pc('u'); pc('e'); pc('r');	pc('y'); pc('!'); pc('\n');
					// printf("Invalid query!\n");
				}
				else 
				{
					if (points[x] > points[y])
						neighbour[y] = x;
					else if (points[x] < points[y])
						neighbour[x] = y;
				}
			}
			else if (code == 1)
			{
				int x;
				get(x);
				x--;
				x = big_neighbour(x);
				int ans = x+1;
				print(ans);
			}
		}
	}
	return 0;
}