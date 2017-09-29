#include <bits/stdc++.h>
using namespace std;

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
#define get(z) scanf("%d",&z);

// int a[100005];

int main()
{
	int n,k,i;
	get(n);
	get(k);

	for (i=0; i<k; i++)
	{
		if (i&1)
		{
			// a[i] = n-(i/2);
			printf("%d ", n-(i/2));
		}
		else
		{
			// a[i] = (i/2)+1;
			printf("%d ",(i/2)+1);
		}
	}

	if (k&1)
	{
		for (int j=((k-1)/2)+2; j<=(n-(k-1)/2); j++)
			printf("%d ",j);
	}
	else
	{
		for (int j=(n-(k-1)/2)-1; j>((k-1)/2)+1; j--)
			printf("%d ",j);
	}

	return 0;
}