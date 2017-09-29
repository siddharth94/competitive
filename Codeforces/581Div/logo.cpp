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
#define get(x) scanf("%d",&x)

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

int len[3][2];

int main()
{
	F(i,3)
		F(j,2)
		{
			get(len[i][j]);
		}

	F(i,8)
	{
		int la,lb,lc;
		int ba,bb,bc;
		la = len[0][(i>>2)&1];
		ba = len[0][!((i>>2)&1)];

		lb = len[1][((i>>1)&1)];
		bb = len[1][!((i>>1)&1)];
		
		lc = len[2][i&1];
		bc = len[2][!(i&1)];

		// cout << la << " " << ba << endl;
		// cout << lb << " " << bb << endl;
		// cout << lc << " " << bc << endl;
		// cout << endl;

		if (la+lb+lc == ba && bb == ba && bc == ba)
		{
			cout << ba << endl;
			F(i,ba)
			{
				F(j,la)
					cout << "A";
				F(j,lb)
					cout << "B";
				F(j,lc)
					cout << "C";
				cout << endl;
			}
			return 0;
		}

		else if (la+lb == lc && ba == bb && ba+bc == lc)
		{
			cout << lc << endl;
			F(i,ba)
			{
				F(j,la)
					cout << "A";
				F(j,lb)
					cout << "B";
				cout << endl;
			}
			F(i,bc)
			{
				F(i,lc)
					cout << "C";
				cout << endl;
			}
			return 0;
		}
		else if (la+lc == lb && ba == bc && ba+bb == lb)
		{
			cout << lb << endl;
			F(i,ba)
			{
				F(j,la)
					cout << "A";
				F(j,lc)
					cout << "C";
				cout << endl;
			}
			F(i,bb)
			{
				F(i,lb)
					cout << "B";
				cout << endl;
			}	
			return 0;
		}
		else if (lb+lc == la && bc == bb && ba+bb == la)
		{
			cout << la << endl;
			F(i,bc)
			{
				F(j,lc)
					cout << "C";
				F(j,lb)
					cout << "B";
				cout << endl;
			}
			F(i,ba)
			{
				F(i,la)
					cout << "A";
				cout << endl;
			}
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}