#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

class comm
{
	public:
		int i;
		int j;
		int freq;
		comm();
};

comm::comm()
{
	freq=0;
}

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
	
	comm incre[p];
	int k=0,i=0;
	while (i<p)
	{
		int prev_i=incr[i].i;
		int prev_j=incr[i].j;
		incre[k].i=incr[i].i;
		incre[k].j=incr[i].j;
		while (incr[i].i==prev_i && incr[i].j==prev_j)
		{
			incre[k].freq++;
			i++;
		}
		k++;
	}
	
	int j=0;
	for (i=0;i<n;i++)
	{
		int sum=m-1;
		bool flag=false;
		if ((incre[j].i)!=(i+1))
		{
			printf("%d\n",m-1);
			continue;
		}
		else
			while ((incre[j].i)==(i+1))
			{
				if ((incre[j].j)==1)
				{
					sum-=incre[j].freq;
				}
				if ((incre[j].j)==m)
				{
					sum+=(incre[j].freq);
					break;
				}
				while (incre[j].freq>1)
				{
					bool poss=true;
					int g=j;
					int fre=(incre[j].freq);
					fre=(incre[j].j)+fre-1;
					fre=(fre<m)?fre:m;
					for (int z=((incre[g]).j);z<=fre;z++,g++)
					{
						if (((incre[g].j)==z) && ((incre[g].i)==i+1))
							(incre[g].freq)--;
						else {poss = false; break;}
					}
					if (!poss)
					{
						printf("-1\n");
						flag=true;
						break;
					}
					if ((incre[j].j)!=1)
						sum++;
				}
				j++;
				if (flag)
				{
					while ((incre[j].i)==(i+1))
						j++;
					break;
				}
			}
		if (flag)
			continue;
		printf("%d\n",sum);
	}
	return 0;
}