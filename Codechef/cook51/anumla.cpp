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

multiset<int> subset;
vector <int> bset;
vector <int> subsum;

int main()
{
	int T;
	get(T);
	while (T--)
	{
		multiset<int> :: iterator it,tm;
		int n,tmp;
		get(n);
		int sub = 1<<n;
		F(i,sub)
		{
			get(tmp);
			subset.insert(tmp);
		}
		it = subset.begin();
		subset.erase(it);
		int bsize;
		subsum.push_back(0);
		while(1)
		{

			tmp = *subset.begin();
			bset.push_back(tmp);
			bsize = subsum.size();
			for (int j=0; j<bsize; j++)
			{
				subsum.push_back(tmp+subsum[j]);
				it = subset.find(tmp+subsum[j]);
				subset.erase(it);
			}
			if (bset.size() == n)
				break;
		}
		bsize = bset.size();
		for (int i=0; i<bsize; i++)
			printf("%d ", bset[i]);
		printf("\n");
		subset.clear();
		bset.clear();
		subsum.clear();
	}
	return 0;
}