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

int n;
LL I[30][30],mat[30][30];
int mod;

void mult(LL a_tmp[][30],LL b_tmp[][30])
{
	LL a[n][n],b[n][n];
	F(i,n)
		F(j,n)
		{
			a[i][j] = a_tmp[i][j];
			b[i][j] = b_tmp[i][j];
			mat[i][j] = 0;
		}
	F(i,n)
		F(j,n)
			F(k,n)
			{
				mat[i][k] += (a[i][j]*b[j][k])%mod;
				mat[i][k] %= mod;
			}
	return;
}

void power(int pow)
{
	if (pow==1)
		return;
	else if (pow==2)
		mult(mat,mat);
	else if (pow%2)
	{
		power(pow/2);
		mult(mat,mat);
		mult(mat,I);
	}
	else
	{
		power(pow/2);
		mult(mat,mat);
	}
	return;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		LL sum = 0;
		int k,l;
		get(n);
		get(k);
		get(l);
		F(i,n)
			F(j,n)
				mat[i][j] = I[i][j] = 0;
		F(i,n)
			mat[0][i] = I[0][i] = 1;
		F(i,n-1)
			mat[i+1][i] = I[i+1][i] = 1;
		mod = pow(10,k);
		power(l-n+1);
		F(i,n)
		{
			sum += ((n-1-i)*mat[0][i])%mod;
			sum %= mod;
		}
		printf("%lld\n",sum);
	}
	return 0;
}