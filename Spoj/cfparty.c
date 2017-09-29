#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

inline void get(int *x)
{
    register int c = gc();
    (*x) = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {(*x) = ((*x)<<1) + ((*x)<<3) + c - 48;}
}

inline void print(int n)
{
	register int a1,a2,a3,a4,a5,r;
	r=n;
	a1 = r%10;
	r/=10;
	if (r!=0)
	{
		a2 = r%10;
		r/=10;
		if (r!=0)
		{
			a3 = r%10;
			r/=10;
			if (r!=0)
			{
				a4 = r%10;
				r/=10;
				if (r!=0)
					pc(r+'0');
				pc(a4+'0');
			}
			pc(a3+'0');
		}
		pc(a2+'0');
	}
	pc(a1+'0');
	pc('\n');
}

int main()
{
	int T;
	get(&T);
	while (T--)
	{
		int n;
		get(&n);
		if (n==1)
			printf("0\n");
		else
		{
			int flag = 0;
			if (n&1)
				flag = 1;
			n >>= 1;
			int k = 1;
			while (!(n&k))
			{
				n=n|k;
				k <<= 1;
			}
			n ^= k;
			n <<= 1;
			if (flag)
				n |= 1;
			print(n);
		}
	}
	return 0;
}