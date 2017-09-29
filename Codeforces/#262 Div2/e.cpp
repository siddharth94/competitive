#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define ft first
#define sd second
#define get(n) scanf("%d",&n)
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define LL long long

vector < pii > pt;
vector < LL > dist (3600);
// vector <int> visited (3600);
vector < pii > ans;

int main()
{
	int n,r;
	get(n);
	get(r);

	pt.pb(mp(0,r));

	for (int i=0; i<=r; i++)
	{
		for (int j=1; j<=r; j++)
		{
			if ((i*i)+(j*j) <= r*r)
			{
				if (i!=0 || j!=r)
					pt.pb(mp(i,j));
				pt.pb(mp(-i,-j));
				pt.pb(mp(-j,i));
				pt.pb(mp(j,-i));
			}
		}
	}
	pt.pb(mp(0,0));

	fill(dist.begin(), dist.end(), 0);
	// fill(visited.begin(), visited.end(), 0);

	pii curr = pt[0];
	// visited[0] = 1;
	ans.pb(curr);
	int maxidx, maxd = -1;

	for (int i=1; i<n; i++)
	{
		int sz = pt.size();
		maxd = -1;
		for (int j=0; j<sz; j++)
		{
			dist[j] += (pow((curr.first - pt[j].first),2) + pow((curr.second - pt[j].second),2));
			if (dist[j] > maxd)
			{
				maxd = dist[j];
				maxidx = j; 
			}
		}
		curr = pt[maxidx];
		ans.pb(pt[maxidx]);
	}

	int sz = ans.size();
	LL sum = 0;

	for (int i=0; i<sz; i++)
	{
		for (int j=i; j<sz; j++)
		{
			sum += (pow((ans[i].first - ans[j].first),2) + pow((ans[i].second - ans[j].second),2));
		}
	}

	printf("%lld\n",sum);
	for (int i=0; i<sz; i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}