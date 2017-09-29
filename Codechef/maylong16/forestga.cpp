#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
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

struct tree
{
	int height;
	int rate;
	int min_time;
}trees[100005];

bool cmp(struct tree a, struct tree b)
{
	if (a.min_time != b.min_time)
		return a.min_time < b.min_time;
	else if (a.height != b.height)
		return a.height > b.height;
	else
		return a.rate > b.rate;
}

int bin_search(int init_ht, int rate, int time_start, int time_end, int w)
{
	int begin = time_start;
	int end = time_end;

	if (begin == end)
		return begin + 1;

	int mid = (begin + end)/2;

	while (begin < end)
	{
		if (end - begin == 1)
		{
			if (init_ht + rate*begin == w)
				mid = begin;
			else
				mid = end;
			break;
		}
		mid = (begin + end) >> 1;
		if (init_ht + rate*mid > w)
			begin = mid;
		else if (init_ht + rate*mid < w)
			end = mid;
		else return mid;
	}
	return mid;
}

int main()
{
	int n,w,l;
	get(n);
	get(w);
	get(l);

	F(i,n)
	{
		int h,r;
		get(h);
		get(r);
		
		trees[i].height = h;
		trees[i].rate = r;
		trees[i].min_time = (l>h ? ((l-h)%r == 0 ? (l-h)/r : (l-h)/r + 1)  : 0);
	}

	sort(trees, trees+n, cmp);

	int h = 0;
	int r = 0;
	int t = 0;

	int ans;
	bool found = false;

	for (int i=0; i<n; i++)
	{
		h += trees[i].height;
		r += trees[i].rate;
		t = trees[i].min_time;

		int cur_ht = h + t*r;

		if (cur_ht >= w)
		{
			int h_s = h - trees[i].height;
			int r_s = r - trees[i].rate;
			int t_s = 0;
			if (i>0)
				t_s = trees[i-1].min_time;
			else
			{
				ans = t;
				found = true;
				break;
			}

			ans = bin_search(h_s, r_s, t_s, t, w);
			found = true;
			break;
		}
	}

	if (!found)
	{
		ans = ((w-h)%r == 0 ? (w-h)/r : (w-h)/r + 1);
	}

	printf("%d\n", ans);
	return 0;
}