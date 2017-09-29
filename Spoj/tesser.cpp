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


int table[100005];

char txt[100005];
char pat[100005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		n--;

		memset(table, 0, sizeof table);

		int prev, curr;
		get(prev);

		F(i,n)
		{
			get(curr);
			if (curr > prev)
				txt[i] = 'G';
			else if (curr < prev)
				txt[i] = 'L';
			else
				txt[i] = 'E';
			prev = curr;
		}

		scanf("%s",pat);

		int l = strlen(pat);
		int j = 0;

		table[0] = 0;

		R(i,1,l)
		{
			while (j>0 && pat[i] != pat[j])
				j = table[j-1];

			if (pat[i] == pat[j])
				table[i] = ++j;
		}

		j = 0;
		bool f = false;

		F(i,n)
		{
			while (j>0 && txt[i] != pat[j])
				j = table[j-1];

			if (txt[i] == pat[j])
			{
				j++;
				if (j==l)
				{
					printf("YES\n");
					f = true;
					break;
				}
			}
		}

		if (!f)
			printf("NO\n");

	}
	return 0;
}