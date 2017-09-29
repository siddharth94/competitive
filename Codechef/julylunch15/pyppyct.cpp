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

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

LL ebit[3000006];
LL obit[3000006];
vector < pii > xy;
bool ldiag[3000006];
bool rdiag[3000006];

void update(LL x, LL n, int b)
{
	while (x<=n)
	{
		if (b)
			obit[x] += 1;
		else
			ebit[x] += 1;
		x = x + (x&-x);
	}
}

LL query(LL x, int b)
{
	// int b = x%2;
	LL s = 0;
	while (x>0)
	{
		if (b)
			s += obit[x];
		else
			s += ebit[x];
		x = x - (x&-x);
	}
	return s;
}

int main()
{
	LL T;
	getll(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		memset(ebit, 0, sizeof(ebit));
		memset(obit, 0, sizeof(obit));
		memset(ldiag, 0, sizeof(ldiag));
		memset(rdiag, 0, sizeof(rdiag));
		LL n,k;
		getll(n);
		getll(k);
		LL tot = n*n;
		F(i,k)
		{
			LL x,y;
			getll(x);
			getll(y);
			if (!rdiag[x+y])
			{
				update(x+y,2*n, (x+y)%2);

				if (x+y <= n+1)
					tot -= x+y-1;
				else
					tot -= 2*n + 1 - (x+y);
				rdiag[x+y] = true;
			}

			if (!ldiag[x-y+n])
			{
				if (x>y)
					tot -= n-(x-y); 
				else 
					tot -= n-(y-x);
				xy.pb(mp(x,y));
				ldiag[x-y+n] = true;
			}
			// tot++;
		}
		F(i,xy.size())
		{
			LL x = xy[i].ft;
			LL y = xy[i].sd;
			LL fx, fy, lx, ly;
			if (x>=y)
			{
				fx = x-y+1;
				fy = 1;
				lx = n;
				ly = n-(x-y);
			}
			else
			{
				fx = 1;
				fy = y-x+1;
				lx = n-(y-x);
				ly = n;
			}
			LL a = query(fx+fy-1, (fx+fy)%2);
			LL b = query(lx+ly, (lx+ly)%2);
			tot += (b-a);
		}
		xy.clear();
		printf("%lld\n", tot);
	}
	return 0;
}