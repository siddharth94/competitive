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

void getll(LL &x)
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

pair <int, int> dp[32769];

inline int gcd(int a,int b)
{
	return (a==0)?b:gcd(b%a,a);
}

int lcm(int a, int b)
{
	LL prod = (LL)a*(LL)b;
	prod /= (b>a)?gcd(a,b):gcd(b,a);
	if (prod > 1000000006)
		return 1000000006;
	else return (int)prod;
}

int main()
{
	int n;
	int k;
	get(n);
	get(k);
	int tmp[17],s_tmp[17];
	F(i,k)
		get(tmp[i]);
	sort(tmp,tmp+k);
	F(i,k)
		F(j,i)
			if (tmp[j] == -1)
				continue;
			else if (tmp[i]%tmp[j] == 0)
			{
				tmp[i] = -1;
				break;
			}
	int z = 0;
	F(i,k)
		if(tmp[i] != -1)
			s_tmp[z++] = tmp[i];
	int size = 1;
	dp[0] = mp(0,1);
	LL ans = 0;
	for (int i = 0; i<z; i++)
	{
		for (int j=0; j<size; j++)
		{
			int l = lcm(s_tmp[i],dp[j].second);
			dp[size+j] = mp((dp[j].first)+1, (int)l);
			k = n/l;
			if (dp[size+j].first & 1)
				ans += k;
			else
				ans -= k;
		}
		size <<= 1;
	}
	print(n-ans);
	return 0;
}