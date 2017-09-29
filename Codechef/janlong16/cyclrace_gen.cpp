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
	int time;
	int cycl;
	int speed;
	int type;
}queries[100005];

int speed[100005];

int main()
{
	srand(time(NULL));

	int n = 50000;
	int q = 100000;

	cout << n << " " << q << endl;
	F(i,q)
	{
		int type = rand()%2;
		queries[i].type = type+1;
		if (i!=0)
		{
			queries[i].time = rand()%(1001-queries[i-1].time) + 1000000007%queries[i-1].time;
			while (queries[i].time < queries[i-1].time)
				queries[i].time += 1000000007%queries[i-1].time;
		}
		else
			queries[i].time = rand()%(100);

		cout << queries[i].type << " " << queries[i].time << " "; 

		if (!type)
		{
			queries[i].cycl = (rand()%n)+1;
			queries[i].speed = rand()%(1000000000-speed[queries[i].cycl])+speed[queries[i].cycl]+1;
			speed[i] = queries[i].speed;
			cout << queries[i].cycl << " " << queries[i].speed;
		}
		cout << endl;
	}

	return 0;
}