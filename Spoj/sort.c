#include <stdio.h>
#include <stdlib.h>


struct ele {
	int val;
	int idx;
};

typedef struct ele ele;

int cmp(const void* a, const void* b)
{
   return ( (*(ele*)a).val - (*(ele*)b).val );
}

int main()
{
	ele a[100];
	int n,i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		a[i].val = tmp;
		a[i].idx = i;
	}

	qsort(a, n, sizeof(ele), cmp);

	for (i=0; i<n; i++)
		printf("%d at idx %d\n", a[i].val, a[i].idx);
}