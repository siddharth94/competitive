#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(long long i=a;i<b;i++)
#define RE(i,a,b) for(long long i=a;i<=b;i++)
#define RR(i,a,b) for(long long i=a;i>b;i--)
#define RRE(i,a,b) for(long long i=a;i>=b;i--)
#define F(i,n) for(long long i=0;i<n;i++)
#define FE(i,n) for(long long i=0;i<=n;i++)
#define FR(i,n) for(long long i=n;i>0;i--)
#define FRE(i,n) for(long long i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <long long, long long>
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

LL upper[100008], lower[100008];
vector <LL> spheres;
LL coeff[100008];
LL ans[100008];
LL mod = 1e9+7;

int main()
{
	LL n,m,c;
	cin >> n >> m >> c;
	F(i,n)
	{
		LL up;
		cin >> up;
		upper[up]++;
	}
	F(i,m)
	{
		LL low;
		cin >> low;
		lower[low]++;
	}

	F(i,c+1)
	{
		if (upper[i] != 0 && lower[i] != 0)
			spheres.pb((upper[i]*lower[i]));
	}

	coeff[0] = 1;
	n = spheres.size();
	F(i,n)
	{
		FRE(j,i+1)
		{
			if (j != 0)
				coeff[j] = (coeff[j-1] + (coeff[j]*spheres[i])%mod)%mod;
			else
				coeff[j] = (coeff[j]*spheres[i])%mod;
		}
	}

	FRE(i,n-2)
		ans[n-2-i] = coeff[i];

	F(i,c)
	{
		if (i <= n-2)
			cout << ans[i] << " ";
		else
			cout << "0 ";
	}

	cout << endl;

	return 0;
}