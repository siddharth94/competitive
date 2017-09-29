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

int arr[20005];
int bit[20005];

void update(int x, int val, int n)
{
	while (x <= n)
	{
		bit[x] += val;
		x += (x&(-x));
	}
}

int query(int x)
{
	int sum = 0;
	while(x>0)
	{
		sum += bit[x];
		x -= (x&(-x));
	}
	return sum;
}

int bin_search(int beg, int end, int val)
{
	if (beg > end)
		return -1;

	int mid = (beg+end)>>1;

	int mval = query(mid);
	int ans = mid;

	if (mval == val)
	{
		int k = bin_search(beg, mid-1, val);
		return (k==-1 ? mid : k);
	}

	if (mval < val)
		return bin_search(mid+1, end, val);
	else
		return bin_search(beg, mid-1, val);
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		int sum = 0, left = n, tot = n;
		int curr;

		RE(i,1,n)
		{
			update(i,1,n);
		}

		RE(i,1,n)	
		{
			curr = i;
			if (left <= curr)
			{
				curr -= left;
				left = tot;
				sum = 0;
			}
			if (left <= curr)
				curr %= left;

			int k = bin_search(1,n,curr+sum+1);
			update(k,-1,n);
			arr[k] = i;
			sum += curr;
			left = tot - 1 - query(k);
			tot--;
		}

		RE(i,1,n)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}