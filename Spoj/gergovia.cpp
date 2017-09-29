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

pii pos[100005], neg[100005];

int main()
{
	while (true)
	{
		int n;
		get(n);

		if (n==0)
			break;

		int i=0,j=0;

		F(z,n)
		{
			int x;
			get(x);
			if (x>=0)
				pos[i++] = mp(x,z);
			else
				neg[j++] = mp(-x,z);
		}

		LL ans = 0;
		i--,j--;

		while (i>=0 && j>=0)
		{
			if (pos[i].ft > neg[j].ft)
			{
				ans += neg[j].ft*(abs(pos[i].sd - neg[j].sd));
				pos[i].ft -= neg[j].ft;
				j--;
			}
			else if (pos[i].ft < neg[j].ft)
			{
				ans += pos[i].ft*(abs(pos[i].sd - neg[j].sd));
				neg[j].ft -= pos[i].ft;
				i--;
			}
			else
			{
				ans += pos[i].ft*(abs(pos[i].sd - neg[j].sd));
				neg[j].ft = pos[i].ft = 0;
				i--, j--;
			}
		}

		printf("%lld\n", ans);

	}
	return 0;
}   