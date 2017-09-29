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

int a[105];
int lhs[1000005];
int rhs[1000005];

int main()
{
	int n;
	get(n);
	int lz=0,out=0;
	F(i,n)
		get(a[i]);
	F(i,n)
		F(j,n)
			F(k,n)
				lhs[lz++] = a[i]*a[j] + a[k];
	int rz=0;
	F(i,n)
		F(j,n)
			F(k,n)
			{
				if (a[k] == 0)
					continue;
				rhs[rz++] = (a[i]+a[j])*a[k];
			}
	sort(lhs,lhs+lz);
	sort(rhs,rhs+rz);
	int i=0,j=0;
	while (i<lz && j<rz)
	{
		if (lhs[i]<rhs[j])
			i++;
		else if (lhs[i]>rhs[j])
			j++;
		else
		{
			int l = 1;
			i++;
			while (i<lz && lhs[i-1] == lhs[i]) {
				l++;
				i++;
			}
			int r = 1;
			j++;
			while (j<rz && rhs[j-1] == rhs[j]){
				r++;
				j++;
			}
			out += (l*r);
		}
	}
	printf("%d\n",out);
	return 0;
}