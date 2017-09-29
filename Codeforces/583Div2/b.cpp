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

int a[1005];

int main()
{
	int n;
	cin >> n;
	F(i,n)
		cin >> a[i];
	int info = 0;
	int turns = 0;
	bool flag = true;
	while (info < n)
	{
		if (flag)
		{
			F(i,n)
			{
				if (a[i] <= info)
				{
					a[i] = 2000;
					info++;
				}
				if (info == n)
					break;
			}
		}
		else
		{
			FRE(i,n-1)
			{
				if (a[i] <= info)
				{
					a[i] = 2000;
					info++;
				}
				if (info == n)
					break;
			}	
		}
		flag = !flag;
		if (info < n)
			turns++;
	}
	cout << turns;
	return 0;
}