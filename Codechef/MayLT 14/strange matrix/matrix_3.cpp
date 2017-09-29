#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

class comm
{
	public:
		int i;
		int j;
};

bool comp(const comm &a,const comm &b)
{
	if ((a.i)!=(b.i))
		return ((a.i)<(b.i));
	else return ((a.j)<(b.j));
}

// bool reduce (comm &incre,int j,int m)
// {
// 	for (int i=((incre[j]).j);i<=m;i++,j++)
// 	{
// 		if (incre[j].j==i)
// 			incre[j].freq--;
// 		else return false;
// 	}
// 	return true;
// }

int main()
{
	int n,m,p;
	
	scanf("%d %d %d",&n,&m,&p);
	
	comm incr[p];

	for (int i=0;i<p;i++)
		scanf("%d %d",&((incr[i]).i),&((incr[i]).j));

	std::sort(&(incr[0]),&(incr[p]),comp);
	int j=0;

	for (int i=0;i<n;i++)
	{
		int a[100005]={};
		if ((incr[j].i)!=(i+1))
			printf("%d\n",m-1);
		else
		{
			while ((incr[j].i)==(i+1))
			{
				a[(incr[j].j)-1]++;
				j++;
			}
			int l = j-1;
			bool flag = false;
			while ((incr[l].i)==(i+1))
			{
				if ((incr[l].j)!=m && ((a[(incr[l].j)] - a[(incr[l].j)-1] + 1) < 0))
				{
					flag = true;
				}
				l--;
			}
			if (flag)
			{
				printf("-1\n");
			}
			else printf("%d\n",m-1+a[m-1]-a[0]);
		}
	}
	return 0;
}