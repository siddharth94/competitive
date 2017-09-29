#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(long long i=a;i<b;i++)
#define RE(i,a,b) for(long long i=a;i<=b;i++)
#define RR(i,a,b) for(long long i=a;i>b;i--)
#define RRE(i,a,b) for(long long i=a;i>=b;i--)
#define F(i,n) for(long long i=0;i<n;i++)
#define FE(i,n) for(long long i=0;i<=n;i++)
#define FR(i,n) for(long long i=n;i>0;i--)
#define FRE(i,n) for(long long i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
#define pb push_back
#define ft first
#define sd second
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked

inline void get(long long &x)
{
    register long long c = gc();
    x = 0;
    long long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

long long a[100005], temp[100005];
bool flag;

long long mrge(long long left, long long mid, long long right)
{
  long long i, j, k;
  long long inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant mrged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (a[i] <= a[j])
    {
      if (a[i] == a[j])
      	flag = true;
      temp[k++] = a[i++];
    }
    else
    {
      temp[k++] = a[j++];
  
      inv_count = inv_count + (mid - i);
    }
  }
  
  while (i <= mid - 1)
    temp[k++] = a[i++];
  
  while (j <= right)
    temp[k++] = a[j++];
  
  for (i=left; i <= right; i++)
    a[i] = temp[i];
  
  return inv_count;
}

long long _mrgeSort(long long left, long long right)
{
  long long mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
  
    inv_count  = _mrgeSort(left, mid);
    inv_count += _mrgeSort(mid+1, right);
  
    inv_count += mrge(left, mid+1, right);
  }
  return inv_count;
}

int main()
{
	long long T;
	get(T);
	for (long long __rep = 1; __rep <=T; __rep++)
	{
		memset(temp,0,sizeof(temp));
		memset(a,0,sizeof(a));
		flag = false;
		long long n,k;
		get(n);
		get(k);
		F(i,n)
		{
			get(a[i]);
		}
		long long inv = _mrgeSort(0, n-1);

		if (inv > k)
			printf("Case %lld: %lld\n", __rep, inv-k);
		else if (!flag)
			printf("Case %lld: %lld\n", __rep, (k-inv)%2);
		else
			printf("Case %lld: %lld\n", __rep, 0ll);
	}
	return 0;
}