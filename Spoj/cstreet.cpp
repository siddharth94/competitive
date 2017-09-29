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

vector <pair <int, pair<int, int> > > cost;
int subset[1005];
int rank[1005];
int tot_len;

int find(int x)
{
	if (subset[x] == -1)
		return x;

	subset[x] = find(subset[x]);
	return subset[x];
}

void union2(int x, int y)
{
	if (rank[x] > rank[y])
		subset[y] = x;
	else if (rank[x] < rank[y])
		subset[x] = y;
	else
	{
		subset[y] = x;
		rank[x]++;
	}
}

int kruskal(int n)
{
	memset(subset, -1, sizeof(subset));
	memset(rank, 0, sizeof(rank));

	int e = 0;
	int i = 0;

	while (e < n-1)
	{
		int x,y;
		x = (cost[i].second).first;
		y = (cost[i].second).second;

		int px, py;

		px = find(x);
		py = find(y);

		if (px != py)
		{
			e++;
			union2(px, py);
			tot_len += cost[i].first;
		}
		i++;
	}
	return tot_len;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int p;
		get(p);

		int n,m;
		get(n);
		get(m);

		F(i,m)
		{
			int x,y,c;
			get(x);
			get(y);
			get(c);

			cost.pb(mp(c,mp(x-1,y-1)));
		}
		
		sort(cost.begin(), cost.end());
		tot_len = 0;
		kruskal(n);

		printf("%d\n", tot_len*p);
	}
	return 0;
}