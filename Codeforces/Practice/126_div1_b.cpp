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
#define get(n) scanf("%d",&n);

char s[1000005];
int z[1000005];

void zalgo()
{
	int L,R;
	L = R = -1;
	z[0] = 0;
	int n = strlen(s);

	for (int i=1; i<n; i++)
	{
		if (i>R)
		{
			L = R = i;
			while (R < n && s[R-L] == s[R])
				R++;
			z[i] = R-L;
			R--;
		}
		else if (z[i-L] < R-i+1)
		{
			z[i] = z[i-L];
		}
		else
		{
			L = i;
			while(R < n && s[R-L] == s[R])
				R++;
			z[i] = R-L;
			R--;
		}
	}
}

int main()
{
	scanf("%s",s);
	zalgo();
	int m = 0;
	int ans = -1;
	int n = strlen(s);

	for (int i=1; i<n; i++)
	{
		if (z[i] == n-i && m>=z[i])
		{
			ans = i;
			break;
		}
		else
			m = max(m,z[i]);
	}

	if (ans == -1)
		printf("Just a legend\n");
	else
		printf("%s\n", s+ans);
	return 0;
}