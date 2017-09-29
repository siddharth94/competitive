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

int gcd(int a,int b)
{
	return (a==0)?b:gcd(b%a,a);
}

int gcd1(int n1,string s)
{
	int n2=0, i=0;
	int slen = s.length();
	
    while(i<slen)
    {
    	n2=(n2*10+(s[i]-'0'))%n1;
    	i++;
    }
   return gcd(n2,n1);
}

int main ()
{
	int T;
	get(T);
	while (T--)
	{
		int n1;
		string n2;
		get(n1);
		cin >> n2;
		if(n1==0)
			cout << n2 << endl;
		else
			printf("%d\n",gcd1(n1,n2));
	}
	return 0;
}