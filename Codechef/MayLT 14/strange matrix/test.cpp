#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

struct pos
{
	int i,j;
}incr[100005];

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
	for (x=0;x<p;x++)
	{
		printf("%d\t%d\n",incr[x].i,incr[x].j);
	}
	return 0;
}