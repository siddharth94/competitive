#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(register int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
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

int perm[100006];
vector <pii > sets;

bool compare(pii a, pii b)
{
	if (a.first < b.first)
		return true;
	else return false;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		register int n,m;
		register int a,b;
		bool ans = true;
		get(n);
		get(m);
		F(i,n)
			get(perm[i]);
		F(i,m)
		{
			bool flag = true;
			get(a);
			get(b);
			// for (vector <pii > :: iterator it = sets.begin(); it != sets.end() && flag; it++)
			// {
			// 	if ((*it).first <= b && (*it).first >= a)
			// 	{
			// 		(*it) = mp(a,(*it).second);
			// 		flag = false;
			// 	}
			// 	if ((*it).second >= a && (*it).second <= b)
			// 	{
			// 		(*it) = mp((*it).first,b);
			// 		flag = false;
			// 	}
			// }
			// if (flag)
			sets.push_back(mp(a,b));
		}	
		sort (sets.begin(),sets.end(),compare);
		F(i,m)
		{
			while (sets[i].second < sets[i+1].first)
				i++;
			if (i==m)
				break;
			else
				while (sets[i].second < sets[i+1].second)
				{
					sets[i] = mp(sets[i].first,sets[i+1].second);
					sets.erase(sets.begin()+i+1);
				}
		}
		int j=0,i=0;
		while(i<n)
		{
			while ((i+1)<sets[j].first && perm[i]<sets[j].first)
				i++;
			if ((i+1)!=sets[j].first)
			{
				printf("Impossible\n");
				ans = false;
				break;
			}
			while ((i+1)<=sets[j].second && perm[i]<=sets[j].second)
				i++;
			if ((i+1)!=(sets[j].second)+1)
			{
				printf("Impossible\n");
				ans = false;
				break;
			}
			j++;
		}
		if (ans)
			printf("Possible\n");
		sets.clear();
	}
	return 0;
}