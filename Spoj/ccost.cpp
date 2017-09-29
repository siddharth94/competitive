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

struct tree{
	int x,y,v;
};

bool comp(tree a, tree b)
{
	if (a.x != b.x)
		return (a.x < b.x);
	else return (a.y < b.y);
}

int x[100005],y[100005],v[i];
map <int,int> mapy[100005],mapx[100005];
vector <tree> tmp;
vector <vector <tree> > t;

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n;
		get(n);
		
		F(i,n)
		{
			get(tmp[i].x);
			get(tmp[i].y);
			get(tmp[i].v);
		}
		
		sort(tmp,tmp+n,comp);
		
		int l=0;
		for (int i=1; i<n; i++)
		{
			vector <tree> s;
			while (tmp[i].x == tmp[i-1].x)
				i++;
			copy(tmp+l,tmp+i,s.begin());
			t.push_back(s);
			l=i;
		}

		F(i,l)
		{
			mapx[t[i][0].x] = i;
			int sz = t[i].size();
			F(k,sz)
				mapy[i][t[i][k]] = k;
		}

		
		{
			
		}
		register int q,x1,y1,x2,y2;
		get(q);
		F(i,q)
		{
			get(x1); get(y1); get(x2); get(y2);
			
		}
	}
	return 0;
}