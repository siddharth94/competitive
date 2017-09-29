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
#define get(x) scanf("%d", &x)

int a[100005];

int gcd(int a, int b)
{
	if (a%b==0)
		return b;
	return gcd(b, a%b);
}

int main()
{
	int n;
	get(n);

	int g;

	F(i,n)
	{
		get(a[i]);
		if (i==0) g = a[0];
		g = gcd(g,a[i]);
	}

	int m = 0;

	F(i,n)
	{
		a[i] /= g;
		m = max(m,a[i]);
	}

	if ((m-n)%2)
		printf("Alice\n");
	else
		printf("Bob\n");

	return 0;
}