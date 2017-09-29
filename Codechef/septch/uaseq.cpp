#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
#define pii pair <int, int>
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

map <int,int> cd;
int a[100005];

int main()
{
	int n,k;
	get(n);
	get(k);

	F(i,n)
		get(a[i]);

	if (n>80)
	{
		map <int,int> :: iterator it;
		int max=-1, d, idx;
		
		//get cd with max occurrence
		for (int i=1; i<n; i++)
		{
			it = cd.find(a[i]-a[i-1]);
			if (it != cd.end())
			{
				(it->second)++;
				if (max < it->second){
					max = it->second;
					d = a[i]-a[i-1];
					idx = i;
				}
			}
			else{
				cd[a[i]-a[i-1]] = 1;
				if (max < 1)
				{
					max = 1;
					d = a[i]-a[i-1];
					idx = i;
				}
			}
		}

		//got cd with max occurrence
		//get hold of the term with proper d an calc 1st term
		int a0 = a[idx] - idx*d;
		F(i,n)
		{
			if (a[i] != a0+i*d)
				printf("%d ",a0+i*d);
			else printf("%d ",a[i]);
		}		
	}

	else
	{
		LL a_min = 999999999;
		LL d_min = 999999999;
		for (int i=0; i<n-1; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				float dt = ((float)(a[j]-a[i]))/(j-i);
				int d = (int)(dt);
				if ((float)d != dt){
					continue;
				}
				int ini = a[j] - d*j;
				int r = 0;
				for (int x=0; x<n; x++)
				{
					if (a[x] != ini + d*x)
						r++;
				}
				if (r <= k)
				{
					if (a_min > ini)
					{
						a_min = ini;
						d_min = d;
					}
					else if (a_min == ini)
					{
						if (d_min > d)
							d_min = d;
					}
				}
			}
		}

		for (int i=0; i<n; i++)
		{
			printf("%lld ",a_min+i*d_min);
		}
	}

	return 0;
}