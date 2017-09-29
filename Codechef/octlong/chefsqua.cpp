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

vector < pair<LL, LL> >  pt;
vector <pair <LL, LL> > dist[2005] ;
vector <pair <LL, LL> > dista[2005] ;

// bool comp (pair<LL,LL> a, pair<LL,LL> b)
// {
// 	if (a.ft < b.ft)
// 		return true;
// 	else
// 		return (a.sd < b.sd);
// }

bool lcomp(pair<LL,LL> a, LL val)
{
	if (a.first < val)
		return true;
	else
		return false;
}

int main()
{
	int n;
	get(n);

	if (n==0)
	{
		printf("4\n");
		return 0;
	}

	LL x,y;

	F(i,n)
	{
		getll(x);
		getll(y);
		pt.pb(mp(x,y));
	}

	if (n==1)
	{
		printf("3\n");
		return 0;
	}
	if (n==2)
	{
		printf("2\n");
		return 0;
	}

	for (int i=0;i<n;i++)
	// {
	// 	dist[i].resize(2005);
	// 	dista[i].resize(2005);
	// }
		for (int j=0; j<n; j++)
		{
			dist[i].pb(mp(0,0));
			dista[i].pb(mp(0,0));
		}

	for (LL i=0; i<n; i++)
	{
		dist[i][i] = mp(0,i);
		dista[i][i] = mp(0,i);
		for (LL j=i+1 ; j<n; j++)
		{
			dist[i][j] = mp(((pt[i].ft - pt[j].ft)*(pt[i].ft - pt[j].ft)) + ((pt[i].sd - pt[j].sd)*(pt[i].sd - pt[j].sd)) , j); 
			dist[j][i] = mp(dist[i][j].ft , i);
			dista[i][j] = dist[i][j];
			dista[j][i] = dist[j][i];
		}
		sort( dist[i].begin(), dist[i].end());
	}

	int ans = 2;
	vector<pair <LL,LL> > :: iterator it;

	for (LL i=0; i<n; i++)
	{
		for (LL j=0; j<n-1; j++)
		{
			if (dist[i][j].ft == dist[i][j+1].ft)
			{
				LL k=1;
				while (dist[i][j].ft == dist[i][j+k].ft)
				{
					if (dista [dist[i][j+k].sd] [dist[i][j].sd].ft == dist[i][j].ft<<1 )
					{
						if (ans > 1)
							ans = 1;
						it = lower_bound(dist[i].begin(), dist[i].end(), dist[i][j].ft<<1, lcomp);
						while ((*it).ft == dist[i][j].ft*2)
						{
							if ((dista [(*it).sd][dist[i][j+k].sd].ft == dist[i][j].ft) && (dista[(*it).sd][dist[i][j].sd].ft == dist[i][j].ft))
							{
								printf("0\n");
								return 0;
							}
							++it;
						}
					}
					k++;
				}
			}	
		}
	}
	printf("%d\n",ans);

	return 0;
}