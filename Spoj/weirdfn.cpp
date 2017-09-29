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

set <LL> ft,lt;

int main()
{
	int T;
	get(T);
	LL MOD = 1000000007;
	while (T--)
	{
		LL a,b,c,n;
		getll(a);
		getll(b);
		getll(c);
		getll(n);

		ft.insert(1);

		LL curr, med;
		LL sum = 1;
		set <LL>::iterator kuchb;

		for (int i=1; i<n; i++)
		{
			med = *(ft.rbegin());
			curr = ((a*med)%MOD + (b*(i+1))%MOD + c)%MOD;

			sum += curr;

			if (curr < med)
			{
				ft.insert(curr);
				if (ft.size() > lt.size() + 1)
				{
					kuchb = ft.end();
					--kuchb;
					lt.insert(lt.begin(), *(kuchb));
					ft.erase((kuchb));
				}
			}
			else if (curr>med && lt.size()>0 && curr<*(lt.begin()))
			{
				if (ft.size() == lt.size())
					ft.insert(curr);
				else
					lt.insert(curr);
			}
			else
			{
				lt.insert(curr);
				if (lt.size() > ft.size())
				{
					kuchb = ft.end();
					--kuchb;
					ft.insert((kuchb), *(lt.begin()));
					lt.erase(lt.begin());
				}
			}
		}
	
		ft.clear();
		lt.clear();
		printf("%lld\n",sum);

	}	
	return 0;
}