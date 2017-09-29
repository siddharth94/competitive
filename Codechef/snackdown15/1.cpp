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

pair<int, int> a[55];

bool comp(pii x, pii y)
{
	return x.ft > y.ft;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		
		bool sol = true;
		int sum = 0, tmp;
		
		F(i,n)
		{
			get(tmp);
			if (tmp >= n)
				sol = false;
			sum += tmp;
			a[i] = mp(tmp,i);
		}

		if (sum != n || !sol)
			printf("-1\n");
		else
		{
			sort(a, a+n, comp);
			int voter_count = 0;
			int voted_to[55] = {};
			bool voted[55] = {0};
			int j = 0;
			for (int i=1; i<n && voter_count < (n-1); i++)
			{
				if (a[j].ft != 0)
				{
					voter_count++;
					voted_to[a[i].sd] = a[j].sd;
					(a[j].ft)--;
				}
				else j++,i--;
			}
			if (a[j].ft != 0)
				voted_to[a[0].sd] = a[j].sd;
			else voted_to[a[0].sd] = a[j+1].sd;
			F(i,n)
				printf("%d ", voted_to[i]+1);
			printf("\n");
		}
	}
	return 0;
}