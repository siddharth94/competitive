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

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int x11,y11, x12,y12, x21,y21, x22,y22;
		get(x11);	
		get(y11);	
		get(x12);	
		get(y12);	
		get(x21);	
		get(y21);	
		get(x22);	
		get(y22);

		bool ans = false;

		int o1, o2; // orientation : 1 - vertical, 2 - horizontal

		o1 = x11==x12 ? 1 : 2;	
		o2 = x21==x22 ? 1 : 2;

		if (o1 != o2) // one snake horizontal, one vertical
		{
			if (o1 == 1 && (y21 == y11 || y21 == y12) && (x21 == x11 || x22 == x11 ) ) // if 1st snake vertical, 2nd has to be at one of its endpoints
				ans = true;
			else if (o2 == 1 && (y11 == y21 || y11 == y22) && (x11 == x21 || x12 == x21) ) // if 2nd snake vertical, 1st has to be at one of its endpoints
				ans = true;
			else if ( (o1 == 2 && (x21 == x22 && y21 == y22) && x21 <= max(x11,x12) && x21 >= min(x11,x12) && y11 == y21) || (o2 == 2 && (x11 == x12 && y11 == y12) && x11 <= max(x21,x22) && x11 >= min(x21,x22) && y11 == y21) ) // If one snake is a point snake, and other is horizontal
				ans = true;
		}
		else if (o1 == 1 && (x11 == x22)) // both snakes vertical
		{
			// fix snake 1. check if snake 2 intersects with it.
			int v11, v12;
			int v21, v22;

			v11 = min(y11, y12);
			v12 = max(y11, y12);
			v21 = min(y21, y22);
			v22 = max(y21, y22);

			if (v22 >= v11 && v21 <= v12)
				ans = true;
		}
		else if (y11 == y22) // both snakes horizontal
		{
			// fix snake 1. check if snake 2 intersects with it.
			int v11, v12;
			int v21, v22;

			v11 = min(x11, x12);
			v12 = max(x11, x12);
			v21 = min(x21, x22);
			v22 = max(x21, x22);

			if (v22 >= v11 && v21 <= v12)
				ans = true;	
		}

		if (ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}