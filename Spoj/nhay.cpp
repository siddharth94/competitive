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

// KMP example problem

int main()
{
	LL n;

	while (scanf("%lld",&n) != EOF)
	{
		char* pat = (char *) malloc(n+1*sizeof(char));
		LL* table = (LL*) malloc(n*sizeof(LL));

		scanf("%s",pat);

		table[0] = 0;
		LL j = 0;

		// Build Table
		R(i,1,n)
		{
			while (j>0 && pat[i]!=pat[j])
			{
				j = table[j-1];
			}

			if (pat[i] == pat[j])
			{
				table[i] = j+1;
				j++;
			}
			else
				table[i] = 0;
		}

		char c = ' ';
		int pos = -1;

		j = 0;

		scanf("%*c");
		// KMP
		while (c != '\n')
		{
			scanf("%c",&c);
			pos++;

			while (j>0 && c!=pat[j])
			{
				j = table[j-1];
			}

			if (c == pat[j])
			{
				j++;
				if (j == n)
				{
					printf("%lld\n", pos-n+1);
					j = table[j-1];
				}
			}
		}

		printf("\n");

		free(table);
		free(pat);
	}

	return 0;
}
