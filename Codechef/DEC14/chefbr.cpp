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

vector <int> arr;
LL mat[105][105];
const LL mod = 1e9+7;

LL count(int l, int r)
{
	LL ans = 0;
	if (l>=r)
		return 0;
	if (mat[l][r] != -1)
		return mat[l][r];
	R(i,l,r)
	{
		RE(j,i+1,r)
		{
			if (arr[i] == -arr[j])
			{
				if (mat[i][j] == -1)
					mat[i][j] = 1+count(i+1,j-1);
				ans += mat[i][j];
				ans %= mod;
			}
		}
	}
	// mat[l][r] = ans;
	// mat[l][r] %= mod;
	return ans;
}

LL mulcount(int n, int s)
{
	LL ans = 1;
	R(i,s,n)
	{
		R(j,i+1,n)
		{
			if (arr[i] == -arr[j])
			{
				ans = (mat[i][j]+3mulcount(n,j+1));
			}
		}
	}
}

int main()
{
	int n,k,len;
	get(n);
	memset(mat,-1,sizeof(mat));

	//input
	F(i,n)
	{
		get(k);
		arr.pb(k);
	}

	//remove elements without pair
	F(i,n)
	{
		bool flag = false;

		if (arr[i] < 0)
		{
			R(j,i+1,n)
				if (arr[j] == -arr[i])
				{
					flag = true;
					break;
				}
		}

		else //if (arr[i] > 0)
		{
			F(j,i)
				if (arr[j] == -arr[i])
				{
					flag = true;
					break;
				}
		}

		if (!flag)
			arr.erase(arr.begin()+i);
		n = arr.size();
	}

	n = arr.size();
	LL ans = 0;
	F(i,n)
	{
		R(j,i+1,n)
		{
			if (arr[i] == -arr[j])
			{
				if (mat[i][j] == -1)
					mat[i][j] = 1+count(i+1,j-1);
				ans += mat[i][j];
				ans %= mod;
			}
		}
	}

	LL nans = mulcount(n,0);

	printf("%lld\n",ans+1);
	return 0;
}