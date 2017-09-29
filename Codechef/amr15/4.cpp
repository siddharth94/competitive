#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	long long int test, i, N, k, j;
	
	scanf("%lld", &test);
	
	for(i=0; i<test; i++)
	{
		scanf("%lld %lld", &N, &k);
		
		if(k<N && N>=2*k && k>=0)
		{
			for(j=1;j<=N-k ;j++)
			{	
				printf("%lld ", j+k);
			}
			for(j=1;j<=k;j++)
			{
				printf("%lld ", j);
			}
			printf("\n");
		}
		else
			printf("-1\n");
	}
}
