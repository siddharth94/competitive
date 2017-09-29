#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long 

char arr[1005][1005];

struct query
{
	int x1,y1,x2,y2,c;
}qrs[10005];

int get()
{
	char c=getchar();
	int x=0,flag=0;
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-')
	{
		flag=1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return flag?(-x):x;
}

char getchr()
{
	char c=getchar();
	while (c!='N' && c!='E' && c!='W' && c!='S' && c!='C' && c!='D') c=getchar();
	return c;
}

void construct(int i)
{
	qrs[i].x1 = get();
	qrs[i].y1 = get();
	qrs[i].x2 = get();
	qrs[i].y2 = get();
	qrs[i].c = get();
	if (qrs[i].c == 0)
		qrs[i].c = -1;
}

void display(int ind)
{
	int x = get();
	int y = get();
	int out=0,base;
	char pr;
	F(i,ind)
		if (x<=qrs[i].x2 && x>=qrs[i].x1 && y<=qrs[i].y2 && y>=qrs[i].y1)
			out+=qrs[i].c;
	switch (arr[x-1][y-1])
	{
		case 'N': base = 0; break;
		case 'W': base = 1; break;
		case 'S': base = 2; break;
		case 'E': base = 3; break;
	}
	switch ((out+base)%4)
	{
		case 0: pr = 'N'; break;
		case 1: pr = 'W'; break;
		case 2: pr = 'S'; break;
		case 3: pr = 'E'; break;
	}
	printf("%c\n", pr);
}

int main()
{
	int m,n,i=-1;
	m=get();
	n=get();
	F(z,m)
		F(j,n)
			arr[z][j]=getchr();
	int c = get();
	while (c--)
	{
		char qr = getchr();
		if (qr == 'C')
			construct(++i);
		else if (qr == 'D')
			display(i+1);
	}
	return 0;
}