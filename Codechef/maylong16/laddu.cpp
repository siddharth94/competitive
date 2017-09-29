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

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int act;
		string origin;
		get(act);
		cin >> origin;

		int laddu = 0;

		F(i,act)
		{
			string type;
			cin >> type;

			if (type == "CONTEST_WON")
			{
				int rank;
				get(rank);

				laddu += 300;
				if (rank<20)
					laddu += 20-rank;
			}
			else if (type == "TOP_CONTRIBUTOR")
				laddu += 300;
			else if (type == "BUG_FOUND")
			{
				int sev;
				get(sev);

				laddu += sev;
			}
			else if (type == "CONTEST_HOSTED")
				laddu += 50;
		}

		int ans = 0;

		if (origin == "INDIAN")
			ans = laddu/200;
		else 
			ans = laddu/400;

		printf("%d\n", ans);
	}
	return 0;
}