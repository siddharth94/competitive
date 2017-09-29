#include<cstdio>
#include<iostream>
using namespace std;

long long int a[100005];

// long long int get()
// {
//   char c;
//   while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
//   bool flag=(c=='-');
//   if(flag)
//     c=getchar();
//   long long int x=0;
//   while(c>='0'&&c<='9')
//     {
//       x=x*10+c-48;
//       c=getchar();
//     }
//   return flag?-x:x;
// }

int main()
{
	long long int n,k,max=-2000000005,min=2000000005;
	// n=get();
	// k=get();
	scanf("%lld %lld",&n,&k);
	long long int i;
	bool flag=(k%2==0);
	if (flag)
	{
		for (i=0;i<n;i++)
		{
			// a[i]=get();
			scanf("%lld",&a[i]);
			if (min>a[i])
				min=a[i];
		}
		if (k==0)
		{
			for (i=0;i<n;i++)
			{
				printf("%lld ",a[i]);
			}
			return 0;
		}
		for (i=0;i<n-1;i++)
			printf("%lld ",a[i]-min);
		printf("%lld\n",a[n-1]-min);
	}
	else
	{
		for (i=0;i<n;i++)
		{
			// a[i]=get();
			scanf("%lld",&a[i]);
			if (max<a[i])
				max=a[i];
		}
		for (i=0;i<n-1;i++)
			printf("%lld ",max-a[i]);
		printf("%lld\n",max-a[n-1]);
	}
	return 0;
}