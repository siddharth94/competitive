#include <bits/stdc++.h>
using namespace std;

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

int m[1000005];
vector <int> p;
int mark[400005];

void sieve()
{
	memset(m,0,sizeof(m));
	register int b=0;
	for (register int i=2; i<1000001; i++)
	{
		if (m[i] == 1)
			continue;
		else
		{
			p.push_back(i);
			register LL j=(LL)i*i;
			for (; j<1000001; j+=i)
				m[j] = 1;
		}
	}
	return;
}

int main()
{
	sieve();
	int sz = p.size();
	int T;
	get(T);
	while (T--)
	{
		int m,n;
		get(m);
		get(n);
		memset(mark,0,sizeof(mark));
		if (n < 999998)
		{
			vector <int> :: iterator it = lower_bound(p.begin(),p.end(),m);
			while (*it <= n)
				printf("%d\n",*it++);
		}
		else
		{
			int sq = n;
			F(j,sz)
			{
				if (p[j] > sq)
					break;
				for (int k=m+(p[j]-(m%p[j]==0?p[j]:m%p[j])); k<=n; k+=p[j])
					if (k != p[j])
						mark[k-m] = -1;
			}
			F(i,n-m+1)
				if (mark[i] != -1 && m+i!=1)
					printf("%d\n",m+i);
		}
		printf("\n");
	}
	return 0;
}