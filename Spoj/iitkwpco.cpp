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

LL a[105];

// int b_search(int beg,int end,LL item)
// {
// 	int mid=(beg+end)/2;                       // Find Mid Location of Array
// 	int nmid = mid;
// 	while (a[mid]<0)
// 		{
// 			mid--;
// 			if (mid<0)
// 			{
// 				mid=nmid+1;
// 				while (a[mid]<0)
// 				{
// 					mid++;
// 					if (mid > end)
// 						return -1;
// 				}
// 			}
// 		}

// 	while(beg<=end && a[mid]!=item)      // Compare Item and Value of Mid
// 	{
// 		if(a[mid]<item)
// 			beg=mid+1;
// 		else
// 			end=mid-1;

// 		mid=(beg+end)/2;
// 		nmid = mid;
// 		while (a[mid]<0)
// 		{
// 			mid--;
// 			if (mid<0)
// 			{
// 				mid=nmid+1;
// 				while (a[mid]<0)
// 				{
// 					mid++;
// 					if (mid > end)
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
		int n;
		get(n);
		LL out=0;
		F(i,n)
			getll(a[i]);
		sort(a,a+n);
		F(i,n)
		{
			if (a[i] == -2)
				continue;
			LL tmp = a[i]<<1;
			LL * del = find (a+i,a+n,tmp);
			if (del != a+n)
			{
					*del=-2;
					a[i]=-2;
					out++;
			}
		}
		printf("%lld\n",out);
	}
	return 0;
}