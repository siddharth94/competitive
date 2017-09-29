#include <bits/stdc++.h>
using namespace std;

int a[2005];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	sort (a,a+n);

	int sum=0;
	for (int i=n-1; i>=0; i-=k)
	{
		sum += (a[i]-1)*2;
	}
	printf("%d\n",sum);
	return 0;
}