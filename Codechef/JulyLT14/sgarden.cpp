#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL unsigned long long
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

int a[100005];
int cycles[100005];
unordered_set <int> color;
int num_elements[100005];
map <int, int> factors;

LL power (LL b, LL p, LL mod=1000000007)
{
	if (p==1)
		return b;
	else if (p==0)
		return 1;
	LL p1 = p,ans=1;
	if (p%2 == 0)
	{
		ans = power(b,p/2,mod)%mod;
		ans = (ans * ans)%mod;
	}
	else if (p%2 == 1)
	{
		ans = power (b,p/2,mod)%mod;
		ans = (((ans * ans) %mod) *b)%mod;
	}
	return ans;
}

void factorize(int num)
{
	int p[]={2,3,5,7,11,13, 17,19,23,29,31, 37,41,43,47,53, 59,61,67,71,73, 79,83,89,97,101, 103,107,109,113,127, 131,137,139,149,151, 157,163,167,173,179, 181,191,193,197,199, 211,223,227,229,233, 239,241,251,257,263, 269,271,277,281,283, 293,307,311,313,317};
	int i=0;
	int s = sqrt(num);
	while (num!=1 && p[i] <= s && i<65)
	{
		int count = 0;
		while (num%p[i] == 0)
		{
			num/=p[i];
			count++;
		}
		if (factors.find(p[i]) != factors.end())
		{
			if (factors[p[i]] < count)
				factors[p[i]] = count;
		}
		else
		{
			factors[p[i]] = count;
		}
		i++;
	}
	if (num!=1)
	{
		if (factors.find(num) == factors.end())
		{
			factors[num] = 1;
		}
		else if (factors[num]<1)
		{
			factors[num] = 1;
		}	
	}
}

int count_cycle(int i,int cycle)
{
	num_elements[cycle]++;
	color.erase(i);
	if (color.find(a[i]) != color.end())
		return count_cycle(a[i],cycle);
	else
		factorize(num_elements[cycle]);
		return ++cycle;
}

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n;
		get(n);
		color.clear();
		factors.clear();
		
		F(i,n)
		{
			get(a[i]);
			a[i]--;
			color.insert(i);
		}
		
		int cycle = 0;
		LL ans = 1;
		
		while (!color.empty())
		{
			num_elements[cycle]=0;
			cycle = count_cycle(*(color.begin()),cycle);
		}
		
		for (map <int, int>::iterator it = factors.begin(); it!= factors.end(); ++it)
		{
			ans = (ans * power(it->first,it->second))%1000000007;
			factors.erase(it);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}