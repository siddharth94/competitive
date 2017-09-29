#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
 
char exp[1000005];
 
int main()
{
	// freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",exp);
		int l=strlen(exp),count=0;
		int i=-1,b=0;
		while (++i<l)
		{
			if (exp[i]=='>')
				b--;
			else 
				b++;
			if (b<0)
				break;
			if (b==0)
				count = i+1;
		}
		printf("%d\n",count);
	}
	return 0;
}
