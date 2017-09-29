#include <stdio.h>

#define gc getchar_unlocked

void get(int* x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {(*x) = ((*x)<<1) + ((*x)<<3) + c - 48;}
}

int main()
{
	int n,a,count=0,max=0;
	get(&n);
	int i;
	for (i=0;i<n;i++)
	{
		get(&a);
		if (a==0)
		{
			if (count > max)
				max = count;
			count = 0;
		}
		else count++;
	}
	if (count > max)
		printf("%d\n", count);
	else printf("%d\n",max);
	return 0;
}