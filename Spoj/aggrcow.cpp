#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long 

int get()
{
	char c=getchar();
	int x=0,flag=0;
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-')
	{
		flag=1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return flag?(-x):x;
}

int a[100005];

// int comp (const void * a, const void * b)
// {
//   return ( *(int*)a - *(int*)b );
// }

// bool b_srch(int a[],int n,int max,int min,int c)
// {
// 	int ini = a[0],cow=1;
// 	for (int i=1;i<n;i++)
// 	{
// 		while (a[i] < ini + dist && i<n)
// 			i++;
// 		if (i==n)
// 			continue;
// 		cow++;
// 		ini = a[i];
// 	}
// 	if (cow >= c)
// 		return true;
// 	else return false;
// }

int bin_srch(int a[],int n,int max,int min,int c)
{
	if (min>=max)
		return min;
	int dist = (max + min)/2;
	int ini = a[0],cow=1;
	int min_dist = 1000000099;
	for (int i=1;i<n;i++)
	{
		while (a[i] < ini + dist && i<n)
			i++;
		if (i==n)
			continue;
		cow++;
		if (min_dist > a[i]-ini)
			min_dist = a[i]-ini;
		ini = a[i];
	}
	if (cow < c)
		max = dist;
	else if (cow >= c)
	{
		if (min == dist)
			return min;
		min = dist;
	}
	return bin_srch(a,n,max,min,c);
}

int main()
{
	int T=get();
	while (T--)
	{
		int n,c;
		n=get();
		c=get();
		F(i,n)
			a[i]=get();
		sort (a,a+n);
		int max = a[n-1]-a[0];
		int min = 1;
		printf("%d\n",bin_srch(a,n,max,min,c));
	}	
	return 0;
}