#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
int main()
{
long long int t,n,m,x,i,j,counter=0,k;
scanf("%lld",&t);
for(i=1;i<=t;i++)
{
	scanf("%lld %lld %lld",&n,&m,&x);
	for(j=1;j<=n;j++)
	{
		scanf("%lld",&a[j]);
		a[j]=a[j]%m;
	}
	if(x>=m)
	{
		printf("%lld",n*(n-1)/2+n);
	}
	sort(a+1,a+n+1);	
	//printf("%d",a[1]);
	for(k=1;k<=n;k++)
	{
		if(a[k]<=x)
		{
			//case1
			long long int *j = upper_bound(a+k,a+n+1,x-a[k]);
			j--;
			long long int id1=(j-a)-k;
			if(id1>=0)
			{
				if(id1>0)
				{
					counter=counter+id1;
				}
				id1++;
				counter=counter+id1;
			
			}
			//case 2
			long long int *j1 = lower_bound(a+k, a+n+1, m-a[k]);
			long long int *j2 = upper_bound(a+k, a+n+1, m+x-a[k]);
			id1 = j1-a;
			long long int id2 = j2-a-1;
			if(id1!=0&&id2>=id1)
			counter += id2-id1+1;
			if(id1==k)
			{
				counter=counter+id2-id1;
			}
			else
				counter=counter+id2-id1+1;
			
		}
		else
		{
			long long int *j1 = lower_bound(a+k, a+n+1, m-a[k]);
			long long int *j2 = upper_bound(a+k, a+n+1, m+x-a[k]);
			long long int id1 = j1-a;
			long long int id2 = j2-a-1;
			if(id1!=0&&id2>=id1)
			counter += id2-id1+1;
			if(id1==k)
			{
				counter=counter+id2-id1;
			}
			else
				counter=counter+id2-id1+1;
		}

	}
		printf("%lld\n",counter);	
		counter = 0;
}
return 0;
}
