#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
#define pii pair <int, int>
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{
	LL i =2;
	for (LL i=2; i<=10000000; i++)
	{
		string s = "factor " + to_string(i) + " >>fac.txt";
		char * writable = new char[s.size() + 1];
		std::copy(s.begin(), s.end(), writable);
		writable[s.size()] = '\0';
		system(writable);
		// FILE *fp = fopen("fac.txt","r");

	}
	return 0;
}

// int main(int argc, char const *argv[])
// {
// 	// FILE* fp = fopen("fac.txt", "r");
// 	scanf("%*d: ");
// 	LL max = 0;
// 	for (LL i=2; i<=10000000; i++)
// 	{
// 		// if (i%100000 == 0)
// 		// 	printf("%lld\n", i);
// 		int prev,n;
// 		LL pr = 1,sum = 1;
// 		get(prev);
// 		do
// 		{
// 			get(n);
// 			if (n==prev)
// 				sum++;
// 			else
// 			{
// 				pr*=(sum+1);
// 				sum = 1;
// 			}
// 			prev = n;
// 		}while (n!=i+1);
		
// 		if (pr > max)
// 		{
// 			max = pr;
// 			printf("%lld : %lld\n", i,max);
// 		}
// 	}
// 	printf("%lld\n",max);
// 	return 0;
// }