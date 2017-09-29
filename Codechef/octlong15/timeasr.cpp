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

struct node
{
	string tim;
	int hour;
	int min;
	double angle;

	node(string a, int b, int c, double d)
	{
		tim = a;
		hour = b;
		min = c;
		angle = d;
	}
};

vector < struct node > angle;
long double err;

bool cmp(struct node a, struct node b)
{
	if (a.angle != b.angle)
		return a.angle < b.angle;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else
		return a.min < b.min;
}

bool sea(const struct node a, const double val)
{
	if (a.angle > val)
		return false;
	else if (abs(a.angle - val) <= err)
		return false;
	else return true;
}

void precompute()
{
	for (int hour=0; hour<12; hour++)
	{
		for (int min=0; min<60; min++)
		{
			double ang, ha, ma;
			ma = min*6;
			ha = hour*30 + min/2.0;
			ang = abs(ha-ma);
			if (ang > 180)
				ang = 360 - ang;

			char tm[100];
			sprintf(tm, "%02d:%02d", hour, min);
			string tmp(tm);

			struct node no(tmp, hour, min, ang);

			angle.pb(no);
		}
	}
	sort(angle.begin(), angle.end(), cmp);
}

int main()
{
	err = 1/120.0;
	int T;
	get(T);
	precompute();	

	for (int __rep = 1; __rep <=T; __rep++)
	{
		double a;
		scanf("%lf", &a);
		vector <struct node>::iterator it;
		it = lower_bound(angle.begin(), angle.end(), a, sea);
		while(abs(it->angle - a) <= err)
		{
			cout << it->tim << endl;
			it++;
		}
	}
	return 0;
}