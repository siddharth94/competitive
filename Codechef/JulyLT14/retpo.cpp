#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    // int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') c=gc(); 
    	// {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    // if(neg) x=-x;
}

void getll(LL &x)
{
    register int c = gc();
    x = 0;
    // int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') c=gc(); 
    	// {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    // if(neg) x=-x;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		register LL x,y;
		getll(x);
		getll(y);
		if ((x==1 || x==-1) && y==0)
		{
			printf("3\n");
			continue;
		}
		register LL out = 0;
		if (x<y) 
		{
			out=x;
			out <<= 1;
			y=y-x;
			if (y&1) out+=1;
			y >>= 1;
			out += y<<2;
			printf("%lld\n",out);	
		}
		else
		{
			out=y;
			out <<= 1;
			x=x-y;
			if (x&1) out+=3;
			x >>= 1;
			out += x<<2;
			printf("%lld\n",out);
		}		
	}
	return 0;
}