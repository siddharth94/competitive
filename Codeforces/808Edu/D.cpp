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
#define pii pair <long long, long long>
#define pb push_back
#define ft first
#define sd second
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define get(x) scanf("%d", &x)
#define getll(x) scanf("%lld", &x)

LL a[100005];
pii s[100005];

bool cmp_sort(pii x, pii y)
{
	if (x.ft == y.ft)
		return x.sd < y.sd;
	return x.ft < y.ft;
}

bool cmp_search(pii x, LL val)
{
	return x.ft < val;
}

int main()
{
	int n;
	get(n);

	LL lsum = 0, rsum = 0;
	F(i,n)
	{
		getll(a[i]);
		s[i] = mp(a[i],i);
		rsum += a[i];
	}

	if (rsum%2)
	{
		printf("NO\n");
		return 0;
	}

	sort(s, s+n, cmp_sort);
	bool ans = false;

	F(i,n)
	{
		lsum += a[i];
		rsum -= a[i];

		if (lsum == rsum)
		{
			ans = true;
			break;
		}

		LL diff = abs(lsum - rsum);

		LL req = diff/2;

		pii *k = lower_bound(s, s+n, req, cmp_search);

		if ((*k).first != req)
			continue;

		if (lsum > rsum)
		{
			if ((*k).second <= i)
			{
				ans = true;
				break;
			}
		}
		else
		{
			while ((*k).first == req)
				k++;
			k--;
			if ((*k).second > i)
			{
				ans = true;
				break;
			}
		}
	}

	if (ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}