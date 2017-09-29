#include<bits/stdc++.h>
using namespace std;
int main()
{
	int D[101][101][101];
	int t,n,m,i,j,k,l,b;
	scanf("%d",&t);
	int w[100][100];
	for(l=1;l<=t;l++)
	{
		int a;
		scanf("%d %d",&m,&n);
		b=min(m,n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&w[i-1][j-1]);
			}
		}
		a=w[0][0]+w[0+1][0]+w[0][0+1]+w[0+1][0+1];
		//k=1
		for(i=0;i<=m-2;i++)
		{
			for(j=0;j<=n-2;j++)
			{
				D[i][j][1]=w[i][j]+w[i+1][j]+w[i][j+1]+w[i+1][j+1];
				//printf("i=%d j=%d %d\n",i,j,D[i][j][1]);
				if(D[i][j][1]>a)
				a=D[i][j][1];
				//printf("%d\n",a);
			}
		}	
		//printf("%d\n",a);	
		//k=2
		k=2;
		for(i=0;i<=m-1-k;i++)
		{
			for(j=0;j<=n-1-k;j++)
			{
				D[i][j][2]=w[i][j]+w[i+2][j]+w[i][j+2]+w[i+2][j+2]+w[i+1][j+1];;
				//printf("i=%d j=%d %d\n",i,j,D[i][j][2]);
				if(D[i][j][2]>a)
				a=D[i][j][2];
				//printf("%d\nhello",a);
			}
		}
		//k>=3
		for(k=3;k<=b-1;k++)
		{
			for(i=0;i<=m-1-k;i++)
			{
				for(j=0;j<=n-1-k;j++)
				{
					D[i][j][k]=D[i+1][j+1][k-2]+w[i][j]+w[i+k][j]+w[i][j+k]+w[i+k][j+k];
					if(D[i][j][k]>a)
					a=D[i][j][k];
					//printf("%d\n",a);
				}
			}
		
		}
		printf("%d\n",a);
	}


	return 0;
}
