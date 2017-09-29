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

int sums[100005];
LL tot_sum=0;

void generate_sum(int a[],int n,int curr_sum)
{
	if (n==0)
	{
		if (sums[curr_sum]!=1)
			tot_sum+=curr_sum;
		sums[curr_sum]=1;
	}
	else
	{
		generate_sum (a,n-1,curr_sum);
		curr_sum += a[n-1];
		generate_sum (a,n-1,curr_sum);
	}
	return;
}

int main()
{
	int T = get();
	while (T--)
	{
		memset (sums,0,sizeof(int)*100005);
		tot_sum=0;
		int n=get();
		int a[100];
		F(i,n)
			a[i]=get();
		for (int i = 1; i <= n; ++i)
			generate_sum(a,i,0);
		printf("%lld\n",tot_sum);
	}
	return 0;
}