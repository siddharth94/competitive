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

int main()
{
	int T;
	get(T);
	while (T--)
	{
		char a[3][3];
		register int x=0,o=0,count=0,row,col;
		register char c;

		F(i,3)
			F(j,3)
			{
				for (c=gc(); c!='X' and c!='O' and c!='.'; c=gc());
				a[i][j] = c;
				if (c=='X')
					x++;
				if (c=='O')
					o++;
			}

		if (o > x || x > o+1)
			printf("no\n");
		else
		{
			F(i,3)
			{
				if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0]!='.')
					count++, row=i, col=0;			
				if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i]!='.')
					count++, row=0, col=i;
			}

			if (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[1][1]!='.')
				count++, row=0, col=0;
			if (a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[1][1]!='.')
				count++, row=1, col=1;

			if (count > 1)
				printf("no\n");
			else if (count == 1 && ((a[row][col] == 'X' && x!=o+1) || (a[row][col] == 'O' && x!=o)))
				printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}

