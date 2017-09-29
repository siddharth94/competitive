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
// #define MOD 1000000007

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

int main()
{
	int T;
	get(T);
	LL MOD = 1000000007;
	while (T--)
	{
		priority_queue <LL> ft;
		priority_queue <LL, vector <LL>, greater <LL> > lt;
		LL a,b,c,n;
		getll(a);
		getll(b);
		getll(c);
		getll(n);
		ft.push(1);

		LL fts = 1, lts = 0;

		LL curr, med;
		LL sum = 1;

		for (LL i=1; i<n; i++)
		{
			if (fts >= lts)
				med = ft.top();
			else med = lt.top();
			
			curr = ((a*med) + (b*(i+1)) + c);

			if (curr >= MOD)
				curr = curr%MOD;

			sum += curr;

			if (lts>0 && curr<lt.top())
			{
				ft.push(curr);
				fts++;
			}
			else
			{
				lt.push(curr);
				lts++;
			}

			while (fts > lts+1)
			{
				lt.push(ft.top());
				ft.pop();
				lts++;
				fts--;
			}
			while (lts > fts+1)
			{
				ft.push(lt.top());
				lt.pop();
				lts--;
				fts++;
			}
		}

		printf("%lld\n",sum);
	}
	return 0;
}