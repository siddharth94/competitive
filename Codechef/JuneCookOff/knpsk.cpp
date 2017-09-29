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

int w1[100005],w2[100005];

int main()
{
	int n,w,i=0,j=0;
	LL m=0;
	get(n);
	F(z,n)
	{
		get(w);
		if (w==1)
		{
			get(w1[i]);
			i++;
		}
		else
		{
			get(w2[j]);
			j++;
		}
		m+=(LL)(w);
	}
	sort (w1, w1+i);
	sort (w2, w2+j);
	
	int last_even=0;
	int last_odd=0;

	int odd1,odd2,even1,even2;
	odd1 = even1 = i-1;
	odd2 = even2 = j-1;

	if (i>0)
	{
		last_odd = w1[odd1];
		odd1--;
	}
	printf("%d ",last_odd);

	for(int z=2;z<=m;z++)
	{
		if (z&1 == 1)
		{
			if (odd1 >= 0 && odd2 >=0)
			{
				if (odd1>0 && ((w1[odd1] + w1[odd1-1] > w2[odd2])))
				{
					last_odd+=(w1[odd1] + w1[odd1-1]);
					odd1-=2;
				}
				else if (odd1>=0 && (w1[odd1]>w2[odd2]))
				{
					last_odd+=w1[odd1];
					odd1--;
				}
				else
				{
					last_odd+=w2[odd2];
					odd2--;
				}
			}
			else if (odd1<0 && odd2>=0)
			{
				last_odd+=w2[odd2];
				odd2--;
			}
			else if (odd1>=0 && odd2<0)
			{
				last_odd+=w1[odd1];
				odd1--;
				if (odd1>=0)
				{
					last_odd+=w1[odd1-1];
					odd1--;
				}
			}
			printf("%d ",last_odd);
		}
		else
		{
			if (even1 >= 0 && even2 >= 0)
			{		
				if (even1>0 && ((w1[even1] + w1[even1-1] > w2[even2])))
				{
					last_even+=(w1[even1] + w1[even1-1]);
					even1-=2;
				}
				else if (even1>=0 && (w1[even1]>w2[even2]))
				{
					last_even+=w1[even1];
					even1--;
				}
				else
				{
					last_even+=w2[even2];
					even2--;
				}
			}
			else if (even1<0 && even2>=0)
			{
				last_even+=w2[even2];
				even2--;
			}
			else if (even1>=0 && even2<0)
			{
				last_even+=w1[even1];
				even1--;
				if (even1>=0)
				{
					last_even+=w1[even1-1];
					even1--;
				}
			}
			printf("%d ",last_even);
		}
	}
	printf("\n");
	return 0;
}