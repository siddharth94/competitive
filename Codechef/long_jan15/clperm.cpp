#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
#define pb push_back
#define ft first
#define sd second
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

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

LL arr[100005];

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,k;
		get(n);
		get(k);
		F(i,k)
			getll(arr[i]);
		sort(arr,arr+k);
		LL sum = 0, mi = (n*(n+1))/2;
		mi++;
		F(i,k)
		{
			LL ksum = (arr[i]*(arr[i]-1))/2;
			ksum -= sum;
			if (ksum < arr[i])
			{
				mi = ksum + 1;
				// cout << "ksum" << ksum << endl;
				break;
			}
			while (i<k && ksum >= arr[i])
			{
				sum += arr[i];
				i++;
			}
			if (i>=k)
			{
				mi = (n*(n+1))/2;
				mi -= sum;
				mi++;
				// cout << "mi" << mi << endl;
				break;
			}
			i--;
		}
		// cout << mi << "mi\n";
		if (mi%2)
			printf("Chef\n");
		else printf("Mom\n");
	}
	return 0;
}