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

string t,p;
int a[200005];
bool mark[200005];

bool check(int mid)
{
	memset(mark, false, sizeof mark);

	for(int i=0; i<=mid; i++)
		mark[a[i]-1] = true;

	int i=0, j=0;
	while (i<t.length() && j<p.length())
	{
		if (!mark[i])
		{
			if (t[i] == p[j])
			{
				i++;
				j++;
			}
			else
				i++;
		}
		else i++;
		if (j==p.length())
			return true;
	}
	return false;

}

int main()
{
	cin >> t >> p;

	int n = t.length();

	F(i,n)
		get(a[i]);

	int l=0, r=n-1;
	while (r-l >= 2)
	{
		int mid = (l+r)>>1;
		if (check(mid))
		{
			l=mid+1;
		}
		else
		{
			r = mid-1;
		}
	}

	for (int i=l; i<=r; i++)
	{
		if (check(i))
		{
			if (i==r)
				printf("%d\n", r+1);
			continue;
		}
		else
		{
			printf("%d\n", i);
			break;
		}
	}


	return 0;
}