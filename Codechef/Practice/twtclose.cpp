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

bool a[1500];

int main()
{
	int n,k,g;
	char s[40];
	get(n);
	get(k);
	memset(a,false,sizeof(a));
	int o = 0;
	F(i,k)
	{
		scanf("%s",s);
		if (s[2] == 'I')
		{
			get(g);
			a[g] = !a[g];
			if (a[g])
				o++;
			else o--;
		}
		else 
		{
			memset(a,false,sizeof(a));
			o=0;
		}
		printf("%d\n", o);
	}
	return 0;
}