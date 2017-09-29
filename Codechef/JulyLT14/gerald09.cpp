#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
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
	while (T--)
	{
		int n,m,k;
		get(n);
		get(m);	
		get(k);
		F(i,n)
		{
			F(j,m)
			{
				int c = 1324;
				srand (time(NULL)+c);
				c = rand()%4;
				switch (c)
				{
					case 0:
						printf("A");
						break;
					case 1:
						printf("G");
						break;
					case 2:
						printf("T");
						break;
					case 3:
						printf("C");
						break;
				}
			}
				printf("\n");
			// for (int j=0;j<m/4;j++)
			// 	printf("AGTC");
			// for (int j=0;j<m%4;j++)
			// 	printf("A");
			// printf("\n");
		}	
	}
	return 0;
}