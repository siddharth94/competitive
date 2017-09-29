#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int prime[100005];
int p[100005];

int primes()
{
	int k=0;
	prime[1]=-1;
	for (int i=3;i<100000;i+=2)
	{
		if (prime[i]!=-1)
		{
			prime[i]
			p[k++]=i;
			int j=2;
			int n=i*j;
			while (n<100000)
			{
				prime[n]=-1;
				n = i*(++j);
			}
		}
	}
	return k;
}

int main()
{
	int num_p = primes();
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m,val;
		scanf("%d %d",&n,&m);
		if (m<100000)
		{
			for (int i=n;i<=m;i++)
			{
				if (prime[i])
			}
		}
		int a[m-n+1];
		for (int i=0;i<m-n+1;i++)
			a[i]=0;
		int z = sqrt(m);
		for (int i=0;i<num_p && p[i]<=z;i++)
		{
			int rem = n%p[i];
			if (rem!=0)
				val = n-rem+p[i];
			else val=n;
			while (val<=m)
			{
				a[val-n]=-1;
				val+=p[i];
			}
		}
		if (n<=2)
			printf("2\n");
		for (int i=0;i<m-n+1;i++)
			if (a[i]!=-1 && (n+i)%2!=0)
				printf("%d\n",n+i);
		printf("\n");
	}
	return 0;
}