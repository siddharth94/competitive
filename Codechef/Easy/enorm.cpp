#include<cstdio>
using namespace std;

int get()
{
	char c;
	int x=0;
	c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main()
{
	int n,k,count=0;
	n=get();
	k=get();
	while (n--)
	{
		int num=get();
		if (num%k==0)
			count++;
	}
	printf("%d",count);
	return 0;
}