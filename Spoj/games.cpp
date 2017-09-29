#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long 

int getint()
{
	char c=getchar();
	int x=0,flag=0;
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-')
	{
		flag=1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return flag?(-x):x;
}

int gcd(int a,int b)
{
	return (a==0)?b:gcd(b%a,a);
}

int main()
{
	int T=getint();
	while (T--)
	{
		char num[100];
		scanf ("%s",num);
		string n = num;
		size_t dec = n.find('.');
		if (dec == string::npos)
		{
			printf("1\n");
			continue;
		}
		string frac = n.substr(dec+1);
		int i=0,decimal=0,ex=1;
		while (frac[i] != '\0')
		{
			decimal = decimal*10 + frac[i] - '0';
			ex*=10;
			i++;
		}
		ex /= gcd (decimal,ex);
		printf("%d\n",ex);
	}
	return 0;
}