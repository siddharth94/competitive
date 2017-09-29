#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(long long i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <long long, long long>
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ft first
#define sd second

inline void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void getll(LL &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

vector < pii > vill,dino;

int main()
{
	int T;
	get(T);
	while (T--)
	{
		int n;
		get(n);

		LL tmp;

		F(i,n)
		{
			getll(tmp);
			if (tmp > 0)
				vill.push_back(mp(tmp,i));
			else if (tmp < 0)
				dino.push_back(mp(-tmp,i));
		}

		LL vs = vill.size();
		LL ds = dino.size();

		LL cost = 0;

		for (int i=0,j=0; i<vs && j<ds; )
		{
			if (vill[i].ft > dino[j].ft)
			{
				vill[i].ft -= dino[j].ft;
				cost += dino[j].ft * (abs(vill[i].sd - dino[j].sd));
				j++;
			}
			else
			{
				dino[j].ft -= vill[i].ft;
				cost += vill[i].ft * (abs(vill[i].sd - dino[j].sd));
				i++;				
			}
		}

		printf("%lld\n",cost);

		vill.clear();
		dino.clear();
	}
	return 0;
}