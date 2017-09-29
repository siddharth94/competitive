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

bool check(int x0, int y0, int x1, int y1, int x2, int y2) // find location of (x1,y1) and (x2,y2) wrt line perpendicular to line joining (x1,y1) and (x0,y0)
{
	int sign1, sign2;
	sign1 = ((y1-y0)*(y2-y0))+((x1-x0)*(x2-x0));
	sign2 = ((y1-y0)*(y1-y0))+((x1-x0)*(x1-x0));
	if (sign1*sign2 < 0)
		return false;
	else return true;
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

inline int dist(int x1, int y1, int x2, int y2)
{
	return ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		LL x1,y1,u1,v1,x2,y2,u2,v2;
		getll(x1);	
		getll(y1);	
		getll(u1);	
		getll(v1);
		getll(x2);	
		getll(y2);	
		getll(u2);	
		getll(v2);

		bool acute1 = check(x1,y1,x2,y2,u1,v1);
		bool acute2 = check(x2,y2,x1,y1,u2,v2);

		if ((acute1 and !acute2) or (acute2 and !acute1))
		{
			if (acute1)
				printf("Hero\n");
			else printf("Heroine\n");
		}

		LL h1 = dist(x1,y1,u1,v1);
		LL h2 = dist(x2,y2,u2,v2);

		// int p1_num = abs( ((y1-y2)*u1)+((x2-x1)*v1) - x2*y1 + x1*y2 );
		// int p2_num = abs( ((y1-y2)*u2)+((x2-x1)*v2) - x2*y1 + x1*y2 );

		LL p1_num = abs( ((x2-x1)*(v1-y1)) + ((y1-y2)*(u1-x1)) );
		LL p2_num = abs( ((x2-x1)*(v2-y1)) + ((y1-y2)*(u2-x1)) );

		p1_num = p1_num*p1_num;
		p2_num = p2_num*p2_num;

		LL p1h2 = p1_num*h2;
		LL p2h1 = p2_num*h1;

		if (acute1 and acute2)
		{
			if (p1h2 > p2h1)
				printf("Heroine\n");
			else if (p2h1 > p1h2)
				printf("Hero\n");
			else printf("0\n");
		}

		else if (!acute1 and !acute2)
		{
			if (p1h2 < p2h1)
				printf("Heroine\n");
			else if (p2h1 < p1h2)
				printf("Hero\n");
			else printf("0\n");
		}
	}
	return 0;
}