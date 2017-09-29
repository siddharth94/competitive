#include <cstdio>
using namespace std;

#define LL long long

void f(LL a)
{
	if(a<=2)
	{
		if(a!=1)
			printf("%lld",a);
		return;
	}
	int k=1,power=0;
	while (k<=a)
	{
		power++;
		k = k<<1;
	}
	k = k>>1;
	power--;
	printf("2");
	if (power != 1)
		printf("(");
	f(power);
	a -= k;
	if (a!=0)
	{
		if (power!=1)
		{
			printf(")+");
			if (a!=1)
				f(a);
			else printf("2(0)");
		}
		else printf("+2(0)");
	}
	else if (power != 1)
		printf(")");
}

int main()
{
	LL a;
	while (scanf("%lld",&a)!=EOF)
	{
		printf("\n%lld=",a);
		f(a);
	}
	return 0;
}