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

void add (string a, string b)
{
	int alen = a.length();
	int blen = b.length();
	int out = 0,carry = 0;
	while (alen < blen)
	{
		a+="0";
		alen++;
	}
	while (blen < alen)
	{
		b+="0";
		blen++;
	}
	for (int i=0;i<alen;i++)
	{
		int tmp = a[i]+b[i]-'0'-'0' + carry;
		carry = tmp/10;
		out = out*10 + tmp - (carry*10);
	}
	if (carry > 0)
		out = out*10 + carry;
	printf("%d\n",out);
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		string a,b;
		cin >> a >> b;
		add(a,b);	
	}
	return 0;
}