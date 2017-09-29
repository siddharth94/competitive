#include<cstdio>
using namespace std;

int get()
{
	char c;
	int flag=0,x=0;
	c=getchar();
	while ((c<'0'|| c>'9') && c!='-') c=getchar();
	if (c=='-') {
		flag=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return flag?(-x):x;
}

int main()
{
	int num;
	num=get();
	while (num!=42)
	{
		printf("%d\n",num);
		num=get();
	}
	return 0;
}