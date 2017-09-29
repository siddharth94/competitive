#include <bits/stdc++.h>
using namespace std;

int num[20005], inter[20005], ten[20005];
char str[20002];

int main()
{
	int length, i, temp=0, m, ten_temp=10, j, numb, q, c, test;
	long long  ans=0;
	
	scanf("%s", str);
	length=strlen(str);

	scanf("%d", &q);
	
	for(i=1; i<=length; i++)
		num[i]=str[i-1]-'0';
	num[0]=0;
	
	for(test=0; test<q; test++)
	{
		temp=0;
		ten_temp=10;
		inter[0]=0;
		ans=0;
		ten[0]=1;	
		
		scanf("%d %d", &m, &c);	
		
		for(i=1; i<=length; i++)	
		{
			ten[i]=ten_temp%m;
			ten_temp=ten_temp*10;
		}
		
		for(i=1; i<=length; i++)
		{
			temp=10*temp+num[i];
			inter[i]=temp%m;
		}
		
		for(i=1; i<=length; i++)
		{
			for(j=i; j<=length; j++)
			{
				numb = ((inter[j]-(inter[i-1]*ten[j-i+1])%m)+m)%m;				
				if(numb==c)
					ans++;
			}
		}
	
		printf("%lld\n", ans);
	}
	
	return 0;
}