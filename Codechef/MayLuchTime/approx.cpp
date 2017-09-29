#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

// int get()
// {
// 	char c=getchar();
// 	int x=0,flag=0;
// 	while ((c<'0'||c>'9')&&c!='-') c=getchar();
// 	if (c=='-')
// 	{
// 		flag=1;
// 		c=getchar();
// 	}
// 	while (c>='0'&&c<='9')
// 	{
// 		x=x*10+c-'0';
// 		c=getchar();
// 	}
// 	return flag?(-x):x;
// }

int main()
{
	long long int t;
	scanf("%lld",&t);
	while (t--)
	{
		long long int n,k;
		// n=get();
		// k=get();
		scanf("%lld %lld",&n,&k);
		
		long long int a[1005],tmp;
		
		for (int i=0;i<n;i++)
			scanf("%lld",&a[i]);
			//a[i]=get();
		
		long long int min = 1000000001;
		long long int count=0;

		for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				tmp=abs(a[i]+a[j]-k);
				if (tmp < min)
				{
					min=tmp;
					count=0;
				}
				if (tmp == min)
					count++;
			}
		}

		printf("%lld %lld\n",min,count);
	}
	return 0;
}