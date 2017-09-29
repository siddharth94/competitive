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

char l1[200005], l2[200005];	

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		scanf("%s", l1);
		scanf("%s", l2);
		int n = strlen(l1);
		int i =0, curr_lane = -1, flips = 0;
		while (l1[i] == '.' && l2[i] == '.' && i<n)
			i++;
		if (i<n && l1[i] == '.')
			curr_lane = 1;
		else if (i<n && l2[i] == '.')
			curr_lane = 2;
		else
		{
			printf("NO\n");
			continue;
		}
		while (i<n-1)
			if (curr_lane == 1)
			{
				if (l1[i+1] == '.')
				{
					i++;
					continue;
				}
				else if (l2[i+1] == '.')
				{
					flips++;
					i++;
					curr_lane = 2;
					continue;
				}
				else
				{
					printf("NO\n");
					break;
				}
			}
			else if (curr_lane == 2)
			{
				if (l2[i+1] == '.')
				{
					i++;
					continue;
				}
				else if (l1[i+1] == '.')
				{
					flips++;
					i++;
					curr_lane = 1;
					continue;
				}
				else
				{
					printf("NO\n");
					break;
				}
			}
		if (i == n-1)
			printf("YES\n%d\n", flips);
	}
	return 0;
}