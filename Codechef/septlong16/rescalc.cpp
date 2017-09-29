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

int type[105][10];
int c[105];
int score[105];
pair <int,int> ps[105];

bool cmp(pii a, pii b)
{
	return a.first>b.first;
}

int main()
{
	int T;
	get(T);

	for (int __rep = 1; __rep <=T; __rep++)
	{
		int t;
		int n;
		get(n);

		memset(type,0,sizeof type);

		F(i,n)
		{
			get(c[i]);

			score[i] = c[i];

			F(j,c[i])
			{
				get(t);
				type[i][t-1]++;
			}
		}

		F(i,n)
		{
			sort(type[i], type[i]+6);

			score[i] += type[i][0]*4 + (type[i][1]-type[i][0])*2 + (type[i][2] - type[i][1]);
			ps[i] = mp(score[i],i);
		}

		sort(ps, ps+n, cmp);

		if (ps[0].first == ps[1].first)
			printf("tie\n");
		else if (ps[0].second == 0)
			printf("chef\n");
		else
			printf("%d\n", ps[0].second+1);


	}
	return 0;
}