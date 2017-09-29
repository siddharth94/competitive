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

int **mat;
int **I;
int tmp[3][3];

int main()
{
	int T;
	get(T);
	assert(T<=100000 && T>0);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		mat = new int*[3];
		mat[0] = new int[3];
		mat[1] = new int[3];
		mat[2] = new int[3];

		mat[0][0] = 10; mat[0][1] = 1; mat[0][2] = 0;
		mat[1][0] = 0; mat[1][1] = 4; mat[1][2] = 1;
		mat[2][0] = 0; mat[2][1] = 1; mat[2][2] = 0;

		I = new int*[3];
		I[0] = new int[3];
		I[1] = new int[3];
		I[2] = new int[3];

		I[0][0] = 1; I[0][1] = 0; I[0][2] = 0;
		I[1][0] = 0; I[1][1] = 1; I[2][1] = 0;
		I[2][0] = 0; I[2][1] = 0; I[2][2] = 1;

		int p0, p1, q;
		LL n;
		get(p0);	
		get(p1);	
		get(q);	
		getll(n);
		assert(p0>0 && p0<10);
		assert(p1>0 && p1<10);
		assert(q>0 && q<10);

		bool ans = false;
		
		if (q==1)
		{
			ans = true;
		}
		else if (n==1)
		{
			if (p0%q == 0)
				ans = true;
		}
		else
		{
			n--;
			int **m = I;
			int **po = mat;

			while (n>0)
			{
				if (n&1)
				{
					tmp[0][0] = (m[0][0]*po[0][0] + m[0][1]*po[1][0] + m[0][2]*po[2][0])%q;
					tmp[0][1] = (m[0][0]*po[0][1] + m[0][1]*po[1][1] + m[0][2]*po[2][1])%q;
					tmp[0][2] = (m[0][0]*po[0][2] + m[0][1]*po[1][2] + m[0][2]*po[2][2])%q;

					tmp[1][0] = (m[1][0]*po[0][0] + m[1][1]*po[1][0] + m[1][2]*po[2][0])%q;
					tmp[1][1] = (m[1][0]*po[0][1] + m[1][1]*po[1][1] + m[1][2]*po[2][1])%q;
					tmp[1][2] = (m[1][0]*po[0][2] + m[1][1]*po[1][2] + m[1][2]*po[2][2])%q;

					tmp[2][0] = (m[2][0]*po[0][0] + m[2][1]*po[1][0] + m[2][2]*po[2][0])%q;
					tmp[2][1] = (m[2][0]*po[0][1] + m[2][1]*po[1][1] + m[2][2]*po[2][1])%q;
					tmp[2][2] = (m[2][0]*po[0][2] + m[2][1]*po[1][2] + m[2][2]*po[2][2])%q;

					m[0][0] = tmp[0][0]; 
					m[0][1] = tmp[0][1];
					m[0][2] = tmp[0][2];

					m[1][0] = tmp[1][0];
					m[1][1] = tmp[1][1];
					m[1][2] = tmp[1][2];

					m[2][0] = tmp[2][0];
					m[2][1] = tmp[2][1];
					m[2][2] = tmp[2][2];
				}

				tmp[0][0] = (po[0][0]*po[0][0] + po[0][1]*po[1][0] + po[0][2]*po[2][0])%q;
				tmp[0][1] = (po[0][0]*po[0][1] + po[0][1]*po[1][1] + po[0][2]*po[2][1])%q;
				tmp[0][2] = (po[0][0]*po[0][2] + po[0][1]*po[1][2] + po[0][2]*po[2][2])%q;

				tmp[1][0] = (po[1][0]*po[0][0] + po[1][1]*po[1][0] + po[1][2]*po[2][0])%q;
				tmp[1][1] = (po[1][0]*po[0][1] + po[1][1]*po[1][1] + po[1][2]*po[2][1])%q;
				tmp[1][2] = (po[1][0]*po[0][2] + po[1][1]*po[1][2] + po[1][2]*po[2][2])%q;

				tmp[2][0] = (po[2][0]*po[0][0] + po[2][1]*po[1][0] + po[2][2]*po[2][0])%q;
				tmp[2][1] = (po[2][0]*po[0][1] + po[2][1]*po[1][1] + po[2][2]*po[2][1])%q;
				tmp[2][2] = (po[2][0]*po[0][2] + po[2][1]*po[1][2] + po[2][2]*po[2][2])%q;

				po[0][0] = tmp[0][0];
				po[0][1] = tmp[0][1];
				po[0][2] = tmp[0][2];
				po[1][0] = tmp[1][0];
				po[1][1] = tmp[1][1];
				po[1][2] = tmp[1][2];
				po[2][0] = tmp[2][0];
				po[2][1] = tmp[2][1];
				po[2][2] = tmp[2][2];

				n/=2;
			}

			int k = (m[0][0]*p0 + m[0][1]*p1 + m[0][2]*p0)%q;
			if (k==0)
				ans = true;
		}

		if (ans)
			printf("YES\n");
		else
			printf("NO\n");

		free(mat);
		free(I);
	}
	return 0;
}