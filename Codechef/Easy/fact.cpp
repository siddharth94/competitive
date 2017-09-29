#include<cstdio>
#include<cmath>
using namespace std;

int get()
{
	char c;
	int x=0;
	c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&& c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main()
{
	int t=get();
	while (t--)
	{
		int i=1,s=0,num=get(),e=0;
		while (s=(num/pow(5,i++))>0)
			e+=s;
		printf("%d\n",e );
	}
	return 0;
}