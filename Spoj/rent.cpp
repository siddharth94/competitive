#include <bits/stdc++.h>
using namespace std;

#define F(i,a,n) for(int i=a;i<n;i++)
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

inline void getll(LL &x)
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
	int st, end;
	LL p;
}arr[10005];

int e[10005];
LL maxp[2000005];

bool comp(node l, node r)
{
	return l.end < r.end;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		memset(maxp, 0, sizeof(maxp));
		int n;
		get(n);
		int st,d;
		LL p;
		F(i,0,n)
		{
			get(st);
			get(d);
			getll(p);
			arr[i].st = st;
			arr[i].end = st+d;
			arr[i].p = p;
			e[i] = arr[i].end;
		}
		LL m = -1;
		sort (arr, arr+n, comp);
		sort (e, e+n);
		maxp[arr[0].end] = arr[0].p;
		F(i,1,n)
		{
			int *t = lower_bound(e,e+i,arr[i].st);
			if (*t != arr[i].st)
			{
				if (t == e)
				{
					maxp[arr[i].end] = max(arr[i].p, maxp[arr[i-1].end]);
					if (m > maxp[arr[i].end])
						m = maxp[arr[i].end];
					continue;
				}
				t--;
			}
			maxp[arr[i].end] = max(maxp[*t] + arr[i].p, maxp[arr[i].end]);
			maxp[arr[i].end] = max(maxp[arr[i-1].end], maxp[arr[i].end]);
			if (maxp[arr[i].end] > m)
				m = maxp[arr[i].end];
		}
		printf("%lld\n",m);
	}
	return 0;
}