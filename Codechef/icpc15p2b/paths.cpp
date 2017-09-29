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

LL m1 = 1999999973;
LL m2 = 999999937;
LL m3 = 1000000009;

LL ncr[2015][2015][3];

void ncr_calc()
{
	for (int i=0; i<=2008; i++)
	{
		for (int j=0; j<=i; j++)
		{
			if (j==0 || j==i)
				ncr[i][j][0] = ncr[i][j][1] = ncr[i][j][2] = 1;
			else
			{
				ncr[i][j][0] = (ncr[i-1][j-1][0] + ncr[i-1][j][0]) % m1;
				ncr[i][j][1] = (ncr[i-1][j-1][1] + ncr[i-1][j][1]) % m2;
				ncr[i][j][2] = (ncr[i-1][j-1][2] + ncr[i-1][j][2]) % m3;
			}
		}
	}
}

vector < pii > ans;

bool ans_cmp(pii a, pii b)
{
	if (a.ft != b.ft)
		return a.ft < b.ft;
	else
		return a.sd < b.sd;
}

int main()
{
	ncr_calc();

	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		LL x1 = 0, x2 = 0, x3 = 0;
		string c;
		cin >> c;

		// if (c.length() > 650)
		// {
		// 	printf("The Grid is Too Big!\n" );
		// 	continue;
		// }

		for (int i=0; i<c.length(); i++)
		{
			x1 = x1*10 + c[i]-'0';
			x2 = x2*10 + c[i]-'0';
			x3 = x3*10 + c[i]-'0';
			if (x1 >= m1)
				x1 %= m1;
			if (x2 >= m2)
				x2 %= m2;
			if (x3 >= m3)
				x3 %= m3;
		}

		for(int i=0; i<=2008; i++)
		{
			for (int j=0; j<=i && j<1000; j++)
			{
				if (ncr[i][j][0] == x1 && ncr[i][j][1] == x2 && ncr[i][j][2] == x3)
				{
					if (j+1 <= 1000 && i-j+1 <= 1000)
						ans.pb(mp(j+1, i-j+1));
				}
			}
		}

		if (ans.size() == 0)
		{
			printf("The Grid is Too Big!\n");
			continue;
		}

		sort(ans.begin(), ans.end(), ans_cmp);

		printf("%d\n", (int)(ans.size()));
		F(i,ans.size())
		{
			printf("%d %d\n", ans[i].ft, ans[i].sd);
		}

		ans.clear();
		// vector < pair< LL, pair<int, int> > > :: iterator l1 = lower_bound(nr1.begin(), nr1.end(), x1, cmp1);
		// vector < pair< LL, pair<int, int> > > :: iterator u1 = upper_bound(nr1.begin(), nr1.end(), x1, cmp2);

		// vector < pair< LL, pair<int, int> > > :: iterator l2 = lower_bound(nr2.begin(), nr2.end(), x2, cmp1);
		// vector < pair< LL, pair<int, int> > > :: iterator u2 = upper_bound(nr2.begin(), nr2.end(), x2, cmp2);

		// vector < pair< LL, pair<int, int> > > :: iterator l3 = lower_bound(nr3.begin(), nr3.end(), x3, cmp1);
		// vector < pair< LL, pair<int, int> > > :: iterator u3 = upper_bound(nr3.begin(), nr3.end(), x3, cmp2);
		// if (l1 == u1)// || l2 == u2 || l3 == u3)
		// 	printf("The Grid is Too Big!\n");
		// else
		// {
		// 	// if ((u1-l1) != (u2-l2) || (u1-l1) != (u3-l3) || (u2-l2) != (u3-l3))
		// 	// {
		// 	// 	assert(1==2);
		// 	// }
		// 	// else	
		// 	// {
		// 		printf("%d\n", (int)(u1-l1));
		// 		while (l1!=u1)
		// 		{
		// 			printf("%d %d\n", ((l1->second).second)+1, ((l1->second).first) - ((l1->second).second)+1 );
		// 			l1++;
		// 		}
		// 	// }
		// }
	}
	return 0;
}