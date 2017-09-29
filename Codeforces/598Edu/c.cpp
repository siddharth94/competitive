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
# define PI 3.141592653589793238462643383279502884L
#define get(n) scanf("%d",&n);

pair <double,int> angle[100005];

int main()
{
	int n;
	get(n);

	F(i,n)
	{
		int x,y;
		get(x);
		get(y);
		angle[i].sd = i+1;
		if (x != 0)
			angle[i].ft = atan(y*1.0/x);
		else if (y>0)
			angle[i].ft = PI/2;
		else
			angle[i].ft = (3*PI)/2;

		if (x<0)
			angle[i].ft += PI;

		if (x>0 && angle[i].ft<0)
			angle[i].ft = 2*PI + angle[i].ft;
	}

	sort(angle, angle+n);

	double mi = 2*PI - angle[n-1].ft + angle[0].ft;
	int mx, my;
	mx = angle[0].sd;
	my = angle[n-1].sd;

	F(i,n-1)
	{
		if (mi > angle[i+1].ft-angle[i].ft)
		{
			mi = angle[i+1].ft-angle[i].ft;
			mx = angle[i].sd;
			my = angle[i+1].sd;
		}
	}

	printf("%d %d\n", mx, my);
	return 0;
}