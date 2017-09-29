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

int getstr((char*)(&s))
{
	char c = gc();
	register int i = 0;

	while ((c<48 || c>57) && c!='b') c = gc();
	
	if (c=='b')
	{
		c=gc();
		c=gc();
		c=gc();
		s[0] = 'b';
		s[1] = 'y';
		s[2] = 'e';
		s[3] = '\0';
		return 3;
	}
	
	else
	{
		while (c>47 && c<58)
		{
			s[i++] = c;
			c = gc();
		}
		s[i]='\0';
		return i;
	}
}

int count(char* s, int len, int* brk)
{

}

int main()
{
	char right[30];
	int brk[30];
	while (1)
	{
		int l = getstr(right);
		brk[0] = l;
		count (right,l,brk);
	}
	return 0;
}