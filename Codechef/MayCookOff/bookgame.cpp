#include<cstdio>
#include<iostream>
using namespace std;

long long int dig_calc(long long int n)
{
	int i=0;
	long long int count=0;
	while (n%pow(10,i)>0)
	{
		count++;
		i++;
	}
	return count;
}

long long int digit_bef(long long int num,int i,int l,int dig_pow[])
{
	dig_pow[i]=num;
	if (i<l)
		num=((num*9)+pow(10,i));
	else return num;
	digit_bef(num,++i,l);
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		long long int n,d;
		scanf("%lld",&n);
		d=dig_calc(n);
		long long int dig_pow[d+1];
		long long int tot_dig=(d-1)*pow(10,d-1) - 1 + d*(n-pow(10,d-1)) ;
		dig_bef=digit_bef(1,1,d-1,dig_pow);
		long long int a[11];
		memset(a,dig_bef,10);
		a[0]--;

		long long int dig=(n)/pow(10,d-1);
		long long int numb=0;
		for (int i=d-1;i>0;i--)
		{
			if (i==d-1)
			{
				for (int j=1;j<dig;j++)
				{
					a[j]+=pow(10,i);
				}
				long long int df=n%pow(10,d-1);
				a[j]+=df+1;
				numb=n-(n%pow(10,d-1));
			}

			else if (((n-numb)/10)!=0)
			{
				while (((n-numb)/10)!=0)
				{
					for (int z=0;z<10;z++)
						a[z]+=dig_pow[i];
					numb+=pow(10,i);
				}
			}
			else
			{
				int last=n%10;
				for (int z=0;z<=last;z++)
					a[z]++;
			}
		}

		int prob_sum;

		for (int i=0;i<10;i++)
		{
			
		}
	}
}