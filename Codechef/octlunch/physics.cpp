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

int a[10006];
map <int,bool> mark;

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n,f,ans=0;
		get(n);
		get(f);

		F(i,n)
			get(a[i]);

		sort(a,a+n);
		int *tmp;

		for (int *it=a; it<a+n;)
		{
			if (mark.find(*it) != mark.end())
			{
				it++;
				continue;
			}
			int count = 0, *p=it,*q;
			int k = *it;
			while(k <= a[n-1])
			{
				p = lower_bound(p,a+n,k);
				if (p == a+n)
					break;
				q = lower_bound(p,a+n,k+1);
				if (k==*it)
					tmp = q;
				count += q-p;
				mark[*p] = true;
				k = k*f;
			}
			ans += (count*(count-1))>>1;
			it = tmp;
		}
		printf("%d\n",ans);
		mark.clear();
	}
	return 0;
}