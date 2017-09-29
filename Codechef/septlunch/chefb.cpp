#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
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

int a[100005];
vector <int> p;
int p0[100005];
int p1[100000];
int m[1000001];

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
			p0[b++] = 1;
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
	register int T;
	get(T);
	while (T--)
	{
		register int n;
		get(n);

		F(i,n)
			get(a[i]);

		register int count = 0,div = 0;
		// sort(a,a+n);

		register int sz = p.size();

		// cout << "S " << sz << endl;
		// int sq = sqrt(a[n-1]);
		for (register int i=0; i<sz; i++)
		{
			p1[i] = 0;
			p0[i] = 1;
			int marked = 0;
			for (int j=0; j<n; j++)
			{
				div = p1[i];
				while (a[j]%p0[i] == 0)
				{
					a[j]/=p0[i];
					while (a[j]%p[i]==0)
					{
						div++;
						a[j]/=p[i];
					}
					if (p0[i] == 1)
						break;
				}
				if (p1[i] < div){
					p0[i] = pow(p[i],div);
					p1[i] = div;
				}
			}
		}
		F(i,sz)
			count += p1[i];
		printf("%d\n", count);
	}
	return 0;
}