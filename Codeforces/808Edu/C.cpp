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
#define get(x) scanf("%d", &x)
#define getll(x) scanf("%lld", &x)

struct cup
{
	int vol;
	int idx;
	int filled;
} a[105];

bool cmp_vol(struct cup x, struct cup y)
{
	return x.vol > y.vol;
}

bool cmp_idx(struct cup x, struct cup y)
{
	return x.idx < y.idx;
}

int main()
{
	int n,w;

	get(n);
	get(w);

	int sum = 0;

	F(i,n)
	{
		int x;
		get(x);
		a[i].vol = x;
		a[i].idx = i;
		a[i].filled = ceil(x*1.0/2);
		sum += ceil(x*1.0/2);
	}

	w -= sum;

	if (w<0)
	{
		printf("-1\n");
	}
	else
	{
		sort(a, a+n, cmp_vol);
		
		int i = 0;
		while (w>0)
		{
			int e = a[i].vol - a[i].filled;

			if (e<w)
			{
				a[i].filled += e;
				w -= e;
			}
			else
			{
				a[i].filled += w;
				w -= w;
				break;
			}
			i++;
		}

		sort(a, a+n, cmp_idx);

		F(i,n)
		{
			printf("%d ", a[i].filled);
		}
		printf("\n");
	}
	return 0;
}