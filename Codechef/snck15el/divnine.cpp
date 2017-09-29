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

char num[100005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		scanf("%s",num);
		int n = strlen(num);
		if (n==1)
		{
			printf("%d\n", ((num[0]-'0')%9)>4 ? 9-((num[0]-'0')%9) : ((num[0]-'0')%9));
			continue;
		}
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			sum += num[i]-'0';
		}
		int rem = sum % 9;
		int ans = 0;
		if (rem > 4)
		{
			ans = 9-rem;
		}
		else
		{
			while (num[0] > '1' && rem > 0)
			{
				num[0]--;
				rem--;
				ans++;
			}
			if (rem != 0)
			{
				for (int i=1; i<n; i++)
				{
					while (num[i] > '0' && rem > 0)
					{
						num[i]--;
						rem--;
						ans++;
					}
					if (rem == 0)
						break;
				}
				if (rem != 0)
					ans = 9-(sum%9);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}