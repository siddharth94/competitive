#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n,i,j,count=0;
	scanf("%d",&n);
	for (i=1;i<=sqrt(n);i++)
		for (j=i;j<=n;j++)
			if (i*j<=n)
				count++;
	printf("%d\n",count);
	return 0;
}

