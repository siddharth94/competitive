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

int pre[500005];
int a[500005];

void precompute(int n, int k)
{
	map <int,int> freq;
	set <int> s;

	int cur = n-1;

	for (int i=n-1; i>=0; i--)
	{
		if (a[i] <= k)
		{
			freq[a[i]]++;
			s.insert(a[i]);
		}
		while (s.size() == k+1)
		{
			pre[cur] = i+1;
			freq[a[cur]]--;
			if (freq[a[cur]] == 0)
			{
				set.erase(a[cur]);
			}
			cur--;
		}
	}
}

int main()
{
	int n,k;
	get(n);
	get(k);

	F(i,n)
	{
		get(a[i]);
	}

	precompute(n,k);

	return 0;

}