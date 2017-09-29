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

int main()
{
    int T;
    get(T);
    for (int __rep = 1; __rep <=T; __rep++)
    {
        LL l, r;
        
        getll(l);
        getll(r);
        
        LL ans = 0;
        if(l==1)
            ans = 1;
        LL n = 1;
        for(LL i=1; i<=log2(r); i++)
        {
            n*=2;
            for(LL j=1; (n*j)<=r; j*=3)
                if((n*j)>=l)
                    ans++;
        }
        printf("%lld\n", ans);
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// #define R(i,a,b) for(int i=a;i<b;i++)
// #define RE(i,a,b) for(int i=a;i<=b;i++)
// #define RR(i,a,b) for(int i=a;i>b;i--)
// #define RRE(i,a,b) for(int i=a;i>=b;i--)
// #define F(i,n) for(int i=0;i<n;i++)
// #define FE(i,n) for(int i=0;i<=n;i++)
// #define FR(i,n) for(int i=n;i>0;i--)
// #define FRE(i,n) for(int i=n;i>=0;i--)
// #define mp(a,b) make_pair(a,b)
// #define pii pair <int, int>
// #define pb push_back
// #define ft first
// #define sd second
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
// 	for (int __rep = 1; __rep <=T; __rep++)
// 	{
// 		LL l,r;
// 		getll(l);
// 		getll(r);
// 		LL temp = 1152921504606846976;
// 		cout << log(temp)/log(2) << endl;
// 		int p2 = log(r)/log(2);
// 		int p3 = log(r)/log(3);
// 		LL n2 = 2;
// 		LL ans = 0;
// 		if (l == 1)
// 			ans = 1;
// 		for (int i=1; i<=p2; i++)
// 		{
// 			LL n3 = 1;
// 			for (int j=0; j<=p3; j++)
// 			{
// 				LL num = n2*n3;
// 				if (num >= l && num <= r)
// 					ans++;
// 				n3 *= 3;
// 			}
// 			n2 *= 2;
// 		}
// 		printf("%lld\n", ans);
// 	}
// 	return 0;
// }