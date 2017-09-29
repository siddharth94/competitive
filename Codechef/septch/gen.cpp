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
	// cout << "10000" << endl;
	// cout << "10000000000 51\n";
	// cout << "10000000000 71\n";
	// cout << "10000000000 100000\n";
	// cout << "10000000000 11111\n";
	// for (int i=4; i<10000; i++)
	// {
	// 	srand(i);
	// 	LL k = rand()%10000000000;
	// 	k++;
	// 	LL mod = rand()%100000;
	// 	mod++;
	// 	cout << k << " " << mod << endl;
	// }

	cout << "100 10\n";
	for (int i=1; i<=100; i++)
		cout << i << " ";
	

	return 0;
}