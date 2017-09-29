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


int a[250005];
vector <int> ans;
pair <int, bool> ap[250005];

int gcd ( int f, int b ) { int c; while ( f != 0 ) { c = f; f = b%f; b = c; } return b; } 

bool cmp(pair <int, bool> x, pair <int, bool> y)
{
	return x.ft>y.ft;
}

bool sea(const pair <int, bool> a, const int val)
{
	if (a.ft != val)
		return a.ft>val;
	else
		return a.sd;
}

int main()
{
	int n;
	cin >> n;
	int sq = n*n;
	F(i,sq)
	{
		cin >> a[i];
		ap[i] = mp(a[i],false);
	}
	// sort(a,a+sq,cmp);
	sort(ap,ap+sq,cmp);

	F(i,sq)
	{
		if (!ap[i].sd)
		{
			ap[i].sd = true;
			ans.pb(ap[i].ft);
			F(j,ans.size()-1)
			{
				int g = gcd(ans[j],ap[i].ft);
				pair <int, bool> *p = lower_bound(ap,ap+sq,g,sea);
				
				ap[p-ap].sd = ap[p-ap+1].sd = true;
			}
		}
	}
	F(i,n)
		cout << ans[i] << " ";
	return 0;
}