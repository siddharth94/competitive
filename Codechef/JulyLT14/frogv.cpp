#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(register int i=0;i<n;i++)
#define FE(i,n) for(register int i=0;i<=n;i++)
#define FR(i,n) for(register int i=n;i>0;i--)
#define FRE(i,n) for(register int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

pair <int,int> frog[100005];
pair <int,int> frog_sorted[100005];

bool comp (pair<int,int> a, pair<int,int> b)
{
	return ((a.second) < (b.second));
}

int main()
{
	register int n,k,p;
	get(n);
	get(k);
	get(p);
	
	F(i,n)
	{
		int a;
		get(a);
		frog[i] = make_pair(i,a);
		frog_sorted[i] = make_pair(i,a);
	}

	sort (frog_sorted,frog_sorted+n,comp);

	int poss = 1;
	frog[frog_sorted[0].first].second = poss;

	for (int i=1; i<n; i++)
	{
		if (frog_sorted[i].second-frog_sorted[i-1].second <= k)
			frog[frog_sorted[i].first].second = poss;
		else
		{
			poss++;
			frog[frog_sorted[i].first].second = poss;
		}
	}

	while (p--)
	{
		register int l,r;
		get(l);
		get(r);

		if (frog[--l].second == frog[--r].second)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}