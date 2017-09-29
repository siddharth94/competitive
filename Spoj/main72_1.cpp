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

int sums[100005],subset_sum[100005];
LL tot_sum=0;

int main()
{
	int T=get();
	while (T--)
	{
		tot_sum=0;
		int n=get();
		int a[100];
		memset (sums,0,sizeof(int)*n*1000);
		memset (subset_sum,0,sizeof(int)*n*1000);
		F(i,n)
			a[i]=get();
		subset_sum[0]=0;
		int k=1;
		F(i,n)
		{
			int l=0;
			F(j,k)
			{
				if (sums[subset_sum[j] + a[i]] == 0)
				{
					l++;
					sums[subset_sum[j]+a[i]]=1;
					tot_sum += subset_sum[j] + a[i];
					subset_sum[k+l-1]=subset_sum[j]+a[i];
				}
			}
			k+=l;
		}
		printf("%lld\n",tot_sum);
	}
	return 0;
}