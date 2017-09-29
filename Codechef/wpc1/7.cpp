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

LL j,k;

long long modinv(long long a, LL mod)
{
    long long x = 1, b=a, e = mod-2;
    while (e!=0)
    {
        if (e%2==1)
            x = ((x%mod)*(b%mod))%mod;
        b = ((b%mod)*(b%mod))%mod; e /= 2;
    }
    return x;
}

// def modinv(a, m):
//     g, x, y = egcd(a, m)
//     if g != 1:
//         raise Exception('modular inverse does not exist')
//     else:
//         return x % m

LL pow_mod(LL x, LL y, LL z)
{
    //"Calculate (x ** y) % z efficiently."
    LL number = 1;
    while (y)
    {
        if (y & 1)
            number = ((number%z) * (x%z)) % z;
        y >>= 1;
        x = ((x%z) * (x%z)) % z;
    }
    return number;
}
int main()
{
    LL T;
    getll(T);
    while (T--)
    {  
        LL x,m,n,ans,an;
        getll(x);
        getll(m);
        getll(n);

        ans = (pow_mod(x,(m+1),n)-1)%n;
    	an = modinv((x-1),n);
    	ans = (an*ans) % n;
    	printf("%lld\n", ans);
    }
}