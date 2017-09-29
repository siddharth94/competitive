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

LL bit[1005];
LL tot;

void update(int a, int m)
{
	tot++;
	for (register int i=a; i<=m; i+=(i&(-i)) )
		bit[i]++;
	return;
}

int get_Bit(int a)
{
	LL ret=0;
	for (register int i=a; i>0; i-=(i&(-i)) )
		ret += bit[i];
	return tot-ret;
}

int main()
{
	int T;
	get(T);
	F(z,T)
	{
		vector <int> arr[1005];
		tot = 0;
		memset(bit,0,sizeof(bit));
		LL n,m,k,ans=0;
		getll(n);
		getll(m);
		getll(k);
		register int a,b;
		F(i,k)
		{
			get(a);
			get(b);
			arr[a].push_back(b);
		}
		FE(i,n)
		{
			sort(arr[i].begin(),arr[i].end());
			for (vector <int> :: iterator it=arr[i].begin(); it!=arr[i].end(); ++it)
			{
				update((*it),m);
				ans += get_Bit((*it));
			}
		}
		printf("Test case %d: ",z+1);
		printf("%lld\n",ans);
	}
	return 0;
}