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

LL arr[10005][4];

int main()
{
	register int T;
	register int n;
	register int j = 1;
	arr[1][0]=1;	
	arr[1][1]=1;	
	arr[1][2]=1;	
	arr[1][3]=1;	
	get(T);
	while (T--)
	{
		get(n);
		while (j<n)
		{
			arr[j+1][0] = arr[j][1];
			arr[j+1][1] = arr[j][0] + arr[j][3];
			arr[j+1][2] = arr[j][1] + arr[j][3];
			arr[j+1][3] = arr[j][2];
			j++;
		}
		cout << (arr[n][0]+arr[n][1]+arr[n][2]+arr[n][3]) << endl;
	}
	return 0;
}