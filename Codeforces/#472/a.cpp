#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	if (t&1)
		printf("%d %d\n",9,t-9);
	else
		printf("%d %d\n",8,t-8);
	return 0;
}