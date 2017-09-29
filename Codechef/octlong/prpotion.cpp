#include <bits/stdc++.h>
using namespace std;
 
#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
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
 
int main()
{
  int T;
  get(T);
  while (T--)
  {
    int r=0,g=0,b=0,m;
    int red,blue,green;
     
    get(red);
    get(green);
    get(blue);
    get(m);
     
    int tmp;
     
    F(i,red)
    {
	    get(tmp);
	    if (tmp > r)
	    	r = tmp;
    }
     
    F(i,green)
    {
	    get(tmp);
	    if (tmp > g)
	   		g = tmp;
    }	
     
    F(i,blue)
    {
	    get(tmp);
	    if (tmp > b)
	    	b = tmp;
    }
     
    int ma=0;
     
    F(i,m)
    {
	    if (r>=b && r>=g)
	    {
	    	r>>=1;
	    }
	    else if (b>=r && b>=g)
	    {
	   		b>>=1;
	    }
	    else
	    {
	    	g>>=1;
	    }
    }
     
    ma = max(r,b);
    ma = max(ma,g);
    printf("%d\n",ma);
  }
  return 0;
} 


// #include <bits/stdc++.h>
// using namespace std;

// #define F(i,n) for(int i=0;i<n;i++)
// #define FE(i,n) for(int i=0;i<=n;i++)
// #define FR(i,n) for(int i=n;i>0;i--)
// #define FRE(i,n) for(int i=n;i>=0;i--)
// #define mp(a,b) make_pair(a,b)
// #define pii pair <int, int>
// #define LL long long
// #define gc getchar_unlocked
// #define pc putchar_unlocked

// inline void get(int &x)
// {
//     register int c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }

// inline void getll(LL &x)
// {
//     register int c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }

// int main()
// {
// 	int T;
// 	get(T);
// 	while (T--)
// 	{
// 		LL r=0,g=0,b=0,m;
// 		LL red,blue,green;

// 		getll(red);	
// 		getll(blue);	
// 		getll(green);	
// 		getll(m);

// 		LL tmp;

// 		F(i,red)
// 		{
// 			getll(tmp);
// 			if (tmp > r)
// 				r = tmp;
// 		}

// 		F(i,green)
// 		{
// 			getll(tmp);
// 			if (tmp > g)
// 				g = tmp;
// 		}

// 		F(i,blue)
// 		{
// 			getll(tmp);
// 			if (tmp > b)
// 				b = tmp;
// 		}

// 		LL ma=0;
// 		LL mi=1000000001;

// 		F(i,m)
// 		{
// 			ma = max(r,b);
// 			ma = max(ma,g);
	
// 			if (r>=b && r>=g)
// 				r>>=1;
// 			else if (b>=r && b>=g)
// 				b>>=1;
// 			else
// 				g>>=1;
// 		}

// 		ma = max(r,b);
// 		ma = max(ma,g);
// 		mi = min(mi,ma);
// 		printf("%lld\n",mi);
// 	}
// 	return 0;
// }