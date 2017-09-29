#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct pos
{
	int i;
	int j;
} incr[100005];

int a[100005];

bool comp(const pos &a,const pos &b)
{
	if ((a.i)!=(b.i))
		return ((a.i)<(b.i));
	else return ((a.j)<(b.j)); 
}

int main()
{
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	int x,y=0;
	for (x=0;x<p;x++)
		scanf("%d %d",&((incr[x]).i),&((incr[x]).j));
	std::sort(&incr[0],&incr[p],comp);
	for (x=0;x<n;x++)
	{
		if (((incr[y].i)-1)!=x)			///if no changes in row x+1
			printf("%d\n",m-1);
		else
		{
			memset(a,0,sizeof(a));
			int sum=0;
			bool flag=false;
			int curr_row=incr[y].i;
			while (incr[y].i==curr_row)
			{
				a[(incr[y].j)-1]++;
				y++;
			}
			for (int k=m-1;k>0;k--)
			{
				sum+=a[k]-a[k-1]+1;
				if ((a[k]-a[k-1]+1)<0)
				{
					printf("-1\n");
					flag=true;
					break;
				}
			}
			if (flag)
				continue;
			printf("%d\n",sum);
		}
	}
	return 0;
}