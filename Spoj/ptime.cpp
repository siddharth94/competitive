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

vector <pair<int,int> > prime[20000];

void sieve(int n)
{
	// int p[10005]={};
	for (int i=2;i<=n;i++)
	{
		if (!prime[i].empty())
			continue;
		if (i!=2)
			printf("* ");
		int count = 0;
		int k = i;
		while (k <= n)
		{
			if (!prime[k].empty() && prime[k].back().first == i)
			{
				(prime[k].back().second)++;
				count++;
			}
			else
			{
				prime[k].push_back(make_pair(i,1));
				count++;
			}

			int tmp = k*2;
			while (tmp <= n)
			{
				if (!prime[tmp].empty() && prime[tmp].back().first == i)
				{
					(prime[tmp].back().second)++;
					count++;
				}
				else
				{
					prime[tmp].push_back(make_pair(i,1));
					count++;
				}
				tmp += k;
			}
			k=k*i;
		}
		printf("%d^%d ",i,count);
	}
	// for (int j=2; j<=n; j++)
	// {
	// 	cout << j << " : \t";
	// 	for (vector <pair <int, int> > :: iterator it = prime[j].begin(); it!=prime[j].end(); it++)
	// 	{
	// 		cout << it->first << "^" << it->second << " " ;
	// 	}
	// 	cout << endl;
	// }
}

int main()
{
	int n;
	get(n);
	sieve(n);
	return 0;
}