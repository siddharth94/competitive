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

int grid[2505][2505];

int main()
{
	while(1)
	{
		// F(i,2505)
		// 	F(j,2505)
		// 		grid[i][j]=0;
		int i=1080,j=1080;
		int poly=0,len=0;
		grid[1080][1080]=1;
		string path="";
		
		char c = gc();
		while (c<'A' || c>='Z') c=gc();

		if (c=='Q') break;
		
		while (c!='Q')
		{
			switch (c)
			{
				case 'U':
					i++;
					break;
				case 'D':
					i--;
					break;
				case 'R':
					j++;
					break;
				case 'L':
					j--;
					break;
			}
			if (grid[i][j] == 1)
				poly++;
			else grid[i][j]=1;
			path+=c;
			len++;
			c=gc();
		}
		i=1080;
		j=1080;
		F(k,len)
		{
			switch (path[k])
			{
				case 'U':
					i++;
					break;
				case 'D':
					i--;
					break;
				case 'R':
					j++;
					break;
				case 'L':
					j--;
					break;
			}
			grid[i][j]=0;
		}
		printf("%d\n",poly);
	}
	return 0;
}