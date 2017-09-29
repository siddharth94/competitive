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
#define s(x) scanf("%Lf",&x);

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

char ori[5],w[4];
long double prob[27][27];
long double po[27][27];

void poer(int k)
{
	long double tmp[27][27]={};

	if (k==1)
		return;
	
	poer(k/2);

	F(i,26)
		F(j,26)
			F(k,26)
				tmp[i][j] += po[i][k]*po[k][j];

	F(i,26)
		F(j,26)
		{
			po[i][j] = tmp[i][j];
			tmp[i][j] = 0;
		}

	if (k&1)
	{
		F(i,26)
			F(j,26)
				F(k,26)
					tmp[i][j] += po[i][k]*prob[k][j];
		F(i,26)
			F(j,26)
				po[i][j] = tmp[i][j];
	}
	return;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,k;
		get(n);
		get(k);
		scanf("%s", ori);

		F(i,26)
			F(j,26)
			{
				scanf("%Lf",&prob[i][j]);
				po[i][j] = prob[i][j];
			}

		poer(k);
		// F(i,26)
		// {
		// 	F(j,26)
		// 	{
		// 		printf("%.15Lf", po[i][j]); // << " ";
		// 		if (j!=25) cout << " " ;
		// 	}
		// 	cout << endl;
		// }
		long double ans = 0;

		F(j,n)
		{
			long double tmp = 1;
			scanf("%s",w);
			int l = strlen(ori);
			if (strlen(w) != l)
				continue;
			F(i,l)
			{
				tmp *= po[(int)(ori[i]-'a')][(int)(w[i]-'a')];
			}
			ans += tmp;
		}
		printf("%.15Lf\n",ans);
	}
	return 0;
}