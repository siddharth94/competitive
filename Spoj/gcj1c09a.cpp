#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long 

int get()
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

int main()
{
	int T = get();
	F(z,T)
	{
		char inp[65];
		scanf("%s",inp);
		string in = inp;
		map <char,int> crypt;
		crypt[in[0]] = 1;
		int i=0;
		while (crypt.size() == 1 && i<in.length())
		{
			while (in[i] == in[0])
				i++;
			crypt[in[i]] = 0;
		}

		int num_assign=2;

		for (;i<in.length();i++)
		{
			if (crypt.find(in[i]) == crypt.end())
			{
				crypt[in[i]]=num_assign;
				num_assign++;
			}
		}
		int base = crypt.size();
		LL num=0,conv=1;
		for (string::reverse_iterator it = in.rbegin(); it!=in.rend(); it++)
		{
			num += (crypt[*it])*conv;
			conv *= base;
		}
		printf("Case #%d: %lld\n",z+1,num);
	}
	return 0;
}