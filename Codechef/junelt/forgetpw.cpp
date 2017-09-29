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

void getc(char &x)
{
	register char c = gc();
    for(;(c<33 || c>126);c = gc());
    x = c;	
}

char s[1000005];

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n;
		get (n);
		map <char,char> rule;
		F(i,n)
		{
			char c,p;
			//scanf("%c %c",&c,&p);
			//getchar();
			getc(c);
			getc(p);
			rule[c] = p;
			//cout << c << " = " << rule[c];
		}
		scanf("%s",s);
		int len = strlen(s);
		bool flag1 = true,flag2 = false;
		int begin=-1,dec=-1,end = len;
		//map <char,char>::iterator pos;
		F(i,len)
		{
			if ((rule.find(s[i])) != rule.end())
				s[i] = rule[s[i]];
			
			if ((s[i] != '0' || s[i]=='.') && flag1)
			{
				begin = i;
				flag1 = false;
			}
			
			if (s[i] == '.')
			{
				flag2 = true;
				dec = i;
			}
			
			if (flag2 && s[i]!='0')
				end = i+1;
		}
		if (end == dec+1)
				end--;
		if (begin == end || begin == -1)
			printf("0");
		else
			for (int i = begin; i < end; ++i)
				printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}