#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
#define pb push_back
#define ft first
#define sd second
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked

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

struct node
{
	int id,attr,pr,val;
}css_tmp[100005],css[100005];

bool comp(node a, node b)
{
	if (a.id != b.id)
		return a.id < b.id;
	else if (a.attr != b.attr)
		return a.attr < b.attr;
	else return a.pr < b.pr;
}

int remove(int n)
{
	int j=0;
	for (int i=0; i<n; i++)
	{
		while (i<n-1 && css_tmp[i].id == css_tmp[i+1].id && css_tmp[i].attr == css_tmp[i+1].attr)
			i++;
		css[j].id = css_tmp[i].id;
		css[j].attr = css_tmp[i].attr;
		css[j].pr = css_tmp[i].pr;
		css[j].val = css_tmp[i].val;
		j++;
	}
	return j;
}

bool idcomp(node a, int val)
{
	return a.id < val;
}

bool atcomp(node a, int val)
{
	return a.attr < val;
}

int main()
{
	int n,m;
	get(n);
	get(m);
	
	F(i,n)
	{
		get(css_tmp[i].id);
		get(css_tmp[i].attr);
		get(css_tmp[i].val);
		get(css_tmp[i].pr);
	}
	
	stable_sort(css_tmp,css_tmp+n,comp);
	int sz = remove(n);
	int id, attr;

	F(i,m)
	{
		get(id);
		get(attr);
		node *start = lower_bound(css, css+sz, id, idcomp);
		node *end = lower_bound(start, css+sz, id+1, idcomp);
		node *att = lower_bound(start, end, attr, atcomp);
		printf("%d\n", (*att).val);
	}

	return 0;
}