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
#define getll(x) scanf("%lld", &x)

LL a[200005];

int main()
{
	int n,k;

	get(n);
	get(k);

	F(i,n)
	{
		getll(a[i]);
	}

	LL sum = 0;
	F(i,k)
	{
		sum += a[i];
	}

	double mega_sum = sum;

	for(int i=k; i<n; i++)
	{
		sum += (a[i] - a[i-k]);
		mega_sum += sum;
	}

	mega_sum = mega_sum*1.0;

	printf("%0.8lf\n", mega_sum/(n-k+1));


	// int i=0;
	// int j=n-1;

	// LL mul = 1;
	
	// while (i<=j)
	// {
	// 	if (i<j)
	// 	{
	// 		a[i] = a[i]*mul;
	// 		a[j] = a[j]*mul;
	// 	}
	// 	else
	// 	{
	// 		a[i] = a[i]*mul;
	// 	}

	// 	if (mul != k)
	// 		mul++;

	// 	i++;
	// 	j--;
	// }

	// LL sum = 0;
	// F(i,n)
	// {
	// 	sum += a[i];
	// }

	// printf("%0.8lf\n", sum*1.0/(n-k+1));
	return 0;
}