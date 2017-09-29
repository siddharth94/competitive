#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
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

void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

bool compare (pair<LL,LL> i,pair<LL,LL> j) { return ((i.second)<(j.second)); }

pair<LL,LL> arr[100005];

int main()
{
	LL n,m,h,i;
	getll(n);
	getll(m);
	getll(h);
	F(i,h)
	{
		LL a;
		getll(a);
		arr[i].first=a;
		getll(a);
		arr[i].second=a;
	}
	sort (arr, arr+h, compare);
	LL area = n*m,cost=0;
	for (i=0;i<h;i++)
	{	
		if (area>=arr[i].first)
		{
			cost+=(arr[i].first)*(arr[i].second);
			area-=arr[i].first;
		}
		else 
			break;
	}
	if (i==h && area>0)
		printf("Impossible\n");
	else
	{
		cost+=area*arr[i].second;
		printf("%lld\n",cost);
	}
	return 0;
}