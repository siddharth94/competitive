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

char dna[1000005];
pair<int,int> ab[1000005];
bool flag;

int flip(int n)
{
	int i = n;
	flag = !flag;
	if (flag)
	{
		if (ab[i].second-1 == i)
			return 1;
		while (dna[i] == 'B')
			i--;
		int z = flip(i);
		return 1+(ab[i].first<=z?ab[i].first:z);
	}
	else
	{
		if (ab[i].first-1 == i)
			return 1;
		while (dna[i] == 'A')
			i--;
		int z = flip(i);
		return 1+(ab[i].second<=z?ab[i].second:z);
	}
}

int main()
{
	int n,last_b,b=0;
	get(n);
	dna[0] = gc();
	while (dna[0] != 'A' && dna[0] != 'B')
		dna[0] = gc();
	if (dna[0] == 'A')
		ab[0] = make_pair(1,0);
	else
	{
		last_b = 0;
		b++;
		ab[0] = make_pair(0,1);	
	} 
	for (int i=1; i<n; i++)
	{
		dna[i] = gc();
		ab[i] = ab[i-1];
		if (dna[i] == 'A')
			ab[i].first++;
		else 
		{
			ab[i].second++;
			last_b = i;
			b++;
		}
	}
	flag = false;
	if (!b)
		printf("0\n");
	else
	{
		int k = flip(last_b);
		printf("%d\n",ab[last_b].second<k?ab[last_b].second:k);
	}
	return 0;
}