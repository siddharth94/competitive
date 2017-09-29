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

int main()
{
	int T;
	get(T);
	int tot = T,count=0;
	LL sum=0;
	while (T--)
	{
		LL n,big,small;
		getll(n);
		LL z = ~n;
		int set = __builtin_popcount(n);

		if (set == 0)
		{
			big = -1;
			small = -1;
		}
		else
		{
			int i;
			LL k=1;
			
			//finding big
			for (i=1; i<=32; i++)
			{
				if (k&n)
					break;
				k<<=1;
			}
			int fone = i;

			for (; i<=32; i++)
			{
				if (k&z)
					break;
				k<<=1;
			}
			int fzeroa = i;
			int ones = fzeroa-1-fone;

			fone = i-1;

			if (fzeroa == 33)
				big = -1;
			else
			{
				big = n;
				big = big^(1<<(fone-1));
				big = big^(1<<(fzeroa-1));

				int g=1;
				for (int j=1; j<=fzeroa-2; j++)
				{
					if (j<=ones)
						big = big|(1<<(j-1));
					else
						big = big&(~(1<<(j-1)));
				}
			}

			// cout << "fone " << fone << "\nfzeroa " << fzeroa << endl;
			// cout << big << endl;

			//finding small
			k=1;

			for (i=1; i<=32; i++)
			{
				if (k&z)
					break;
				k<<=1;
			}
			int fzero = i;

			for (; i<=32; i++)
			{
				if (k&n)
					break;
				k<<=1;
			}
			int fonea = i;
			int zeros = fonea-1-fzero;

			fzero = i-1;

			if (fonea == 33)
				small = -1;
			else
			{
				small = n;
				small = small^(1<<(fzero-1));
				small = small^(1<<(fonea-1));

				for (int j=1; j<=fonea-2; j++)
				{
					if (j<=zeros)
						small = small&(~(1<<(j-1)));
					else
						small = small|(1<<(j-1));
				}
			}

			// cout << small << endl;
		}

		if (n*n == big*small)
			count++;
		LL diff = big-small;
		sum += diff;
	}
	printf("%0.6f %0.6f\n", ((double)count)/tot, ((double)sum/tot));
	return 0;
}