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

LL mat[72][72];
LL a[72][72][72]; 

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		F(i,n)
			F(j,n)
				getll(mat[i][j]);
		F(k,n)
			F(i,n)
			{
				a[k][i][i] = mat[k][i];
				R(j,i+1,n)
				{
					a[k][i][j] = a[k][i][j-1]^mat[k][j];
				}
			}
		LL tmpmax=0, omax=0;
		LL tmp[72][72];
		F(x1,n)
		{
			F(y1,n)
			{
				R(t,y1,n)
				{
					tmp[x1][t] = a[x1][y1][t];
					tmpmax = max(tmpmax, tmp[x1][t]);
				}
				R(x2,x1+1,n)
				{
					R(y2,y1,n)
					{
						tmp[x2][y2] = tmp[x2-1][y2]^a[x2][y1][y2];
						tmpmax = max(tmpmax, tmp[x2][y2]);
					}
				}
				omax = max(omax, tmpmax);
			}
		}
		printf("%lld\n", omax);
	}
	return 0;
}