#include <bits/stdc++.h>
using namespace std;

#define get(n) scanf("%d",&n);

int main()
{
	int n,m;
	get(n);
	get(m);

	int count = 0, tmp,rem;

	while (n>0)
	{
		rem = n%m;
		count += n-rem;
		tmp = n/m;
		tmp += rem;
		n = tmp;
		if (n<m)
		{
			count += n;
			break;
		}
	}

	// count += n;

	// while (n/m != 0)
	// {
	// 	n/=m;
	// 	count+=n;
	// }

	printf("%d\n",count);
}