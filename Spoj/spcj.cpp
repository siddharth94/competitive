#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

LL a[100005];

// int b_search(int beg,int end,LL item)
// {
// 	int mid=(beg+end)/2;                       // Find Mid Location of Array

// 	while(beg<=end && a[mid]!=item)      // Compare Item and Value of Mid
// 	{
// 		if(a[mid]<item)
// 			beg=mid+1;
// 		else
// 			end=mid-1;

// 		mid=(beg+end)/2;
// 		int nmid = mid;
// 		while (a[mid]<0)
// 		{
// 			mid--;
// 			if (mid<0)
// 			{
// 				mid=nmid+1;
// 				while (a[mid]<0)
// 				{
// 					mid++;
// 					if (mid > n-1)
// 						return -1;
// 				}
// 			}
// 		}
// 	}

// 	if(a[mid]==item)
// 		return mid;
// 	else
// 		return -1;
// }

int main()
{
	int T;
	get(T);
	while (T--)
	{
		// F(i,100005)
		// 	a[i]=0;
		
		int n;
		get(n);
		LL out=0;

		F(i,n)
			getll(a[i]);
		sort(a,a+n);
		
		LL i=n-1,j=n-1,tmp;
		tmp = a[i]>>1;
		
		while (a[j] > tmp)
			j--;
		
		while (i>=0 && j>=0)
		{
			LL tmp = a[i]>>1;
			if (tmp==a[j])
			{
				out++;
				a[i]=-2;
				a[j]=-2;
				while (a[i]<0)
					i--;
				while (a[j]<0 || j>=i)
					j--;
			}
			else if (tmp > a[j])
			{
				i--;
				while (a[i]<0)
					i--;
			}
			else if (tmp < a[j])
			{
				j--;
				while (a[j]<0)
					j--;
			}
		}
		printf("%lld\n",out);
	}
	return 0;
}
