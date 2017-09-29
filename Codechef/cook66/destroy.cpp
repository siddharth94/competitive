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

int a[50005];
priority_queue < int > freq;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);
		F(i,n)
			get(a[i]);

		sort (a,a+n);
		F(i,n)
		{
			int count = 1;
			while (i<(n-1) && a[i] == a[i+1])
			{
				count++;
				i++;
			}
			freq.push(count);
		}

		int ans = 0;
		while (!freq.empty())
		{
			int a = freq.top();
			freq.pop();
			if (freq.empty())
			{
				ans += a;
				break;
			}
			int b = freq.top();
			freq.pop();

			if (a>1)
				freq.push(a-1);
			if (b>1)
				freq.push(b-1);
			ans += 1;
		}

		// sort(freq.begin(), freq.end(), cmp);

		// int ans = 0;
		// if (freq.size() == 1)
		// 	ans = freq[0];
		// else
		// {
		// 	int i=0, j=1;
		// 	while (i<freq.size() && j<freq.size())
		// 	{
		// 		if (freq[i] > freq[j])
		// 		{
		// 			freq[i] -= freq[j];
		// 			ans += freq[j];
		// 			freq[j] = 0;
		// 			j = max(i+1, j+1);
		// 		}
		// 		else if (freq[i] < freq[j])
		// 		{
		// 			freq[j] -= freq[i];
		// 			ans += freq[i];
		// 			freq[i] = 0;
		// 			i = max(i+1, j+1);
		// 		}
		// 		else
		// 		{
		// 			ans += freq[i];
		// 			freq[i] = freq[j] = 0;
		// 			if (i<j)
		// 			{
		// 				i = j+1;
		// 				j = i+1;
		// 			}
		// 			else
		// 			{
		// 				i = i+1;
		// 				j = i+1;
		// 			}
		// 		}
		// 	}
		// 	i = min(i,j);
		// 	if (freq[i] != 0)
		// 	{
		// 		ans += freq[i];
		// 	}
		// }

		printf("%d\n", ans);
		// freq.clear(); 

	}
	return 0;
}