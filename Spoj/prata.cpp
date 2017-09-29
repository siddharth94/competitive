#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
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

pii rank[55];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int p,l,r,max=0;
		get(p);
		get(l);
		priority_queue < pii , vector < pii >, greater < pii > > pq;

		F(i,l)
		{
			get(r);
			rank[i] = mp(r,2);
			pq.push(mp(r,i));
		}

		pii t;
		int tmp;

		F(i,p)
		{
			t = pq.top();
			pq.push(mp( (t.first + (rank[t.second].first * rank[t.second].second)), t.second));
			pq.pop();
			rank[t.second].second++;
			if (t.first > max)
				max = t.first;
		}

		printf("%d\n",max);
	}
	return 0;
}