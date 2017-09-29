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

char a[9];
int c;

void print()
{
	for (int i=0; i<9; i++)
	{
		printf("%c",a[i]);
		if (i%3==2)
			printf("\n");
	}
	printf("\n");
	c++;
}

void gen(int pos, int ch)
{
	if (ch==0)
		a[pos] = '.';
	else if (ch==1)
		a[pos] = 'X';
	else if (ch==2)
		a[pos] = 'O';

	if (pos == 8)
	{
		print();
		return;
	}

	gen(pos+1,0);
	gen(pos+1,1);
	gen(pos+1,2);

	return;
}

int main()
{
	printf("19683\n");

	gen(0,0);
	gen(0,1);
	gen(0,2);

	cout << c << endl;

	return 0;
}