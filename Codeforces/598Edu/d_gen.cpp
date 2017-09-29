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

char mat[1005][1005];

int main()
{
	cout << "1000 1000 100000" << endl;
	srand(time(NULL));
	F(i,1000)
	{
		F(j,1000)
		{
			if (i==0 || i==999 || j==0 || j==999)
			{
				cout << "*";
				mat[i][j] = '*';
			}
			else
			{
				int r = rand()%2;
				if (r==0)
				{
					cout << "*";
					mat[i][j] = '*';
				}
				else
				{
					cout << ".";
					mat[i][j] = '.';
				}
			}
		}
		cout << "\n";
	}

	F(i,100000)
	{
		int r1 = rand()%1000;
		int r2 = rand()%1000;
		while (mat[r1][r2] != '.')
		{
			r1 = rand()%1000;
			r2 = rand()%1000;
		}
		cout << r1+1 << " " << r2+1 << endl;
	}
	return 0;
}