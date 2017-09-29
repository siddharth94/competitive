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
#define get(n) scanf("%d",&n);

char sk[10005];

int main()
{
	scanf("%s",sk);
	int m;
	get(m);
	string s(sk);
	string left, right;

	int l,r,k, len;
	F(i,m)
	{
		get(l);
		get(r);
		get(k);
		len = k%(r-l+1);
		if (len == 0)
			len = r-l+1;

		len = r-l+1-len;

		l--, r--;
		left = s.substr(l, len);
		right = s.substr(l+len, r-l+1-len);
		F(i,right.length())
		{
			s[l+i] = right[i];
		}
		F(i,left.length())
		{
			s[l+right.length()+i] = left[i];
		}
	}
	cout << s;
	return 0;
}