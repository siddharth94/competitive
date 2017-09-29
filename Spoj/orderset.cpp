#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b);
#define pii pair <int, int>
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

pair <int,char> d[200005],b[200005];
int a[200005];
int bit[200005];
bitset <200005> compress;
map <int,int> css;

void insert(int num, int q)
{
	for (int i=num; i<q; i+=(i&(-i))){
		bit[i]++;
		if (i==0)
			break;
	}
}

void del(int num, int q)
{
	for (int i=num; i<q; i+=(i&(-i))){
		bit[i]--;
		if (i==0)
			break;
	}
}

int get_bit(int a)
{
	int sum=0;
	for(int i=a; i>=0; i-=(i&(-i)))
	{
		sum+=bit[i];
		if(i==0)
			break;
	}
	return sum;
}

int main()
{
	register int q,k;
	get(q);
	// getchar();

	F(i,q)
	{
		scanf("%c %d\n",&d[i].second,&d[i].first);
		b[i].first = d[i].first, b[i].second = d[i].second;
	}

	stable_sort(d,d+q);

	register int l = 1;
	a[0] = d[0].first;
	for(register int i=1; i<q; i++)
	{
		if (d[i].first == a[l-1])
			continue;
		a[l++] = d[i].first;
	}
	
	F(i,l)
		css[a[i]] = i;
	
	F(i,q)
	{
		if (b[i].second == 'I')
		{
			k = css[b[i].first];
			if (compress[k])
				continue;
			else
			{
				compress[k] = 1;
				insert(k,l);
			}
		}
		else if (b[i].second == 'D')
		{
			k = css[b[i].first];
			if (!compress[k])
				continue;
			else
			{
				if (compress[k]!=0)
					del(k,l);
				compress[k] = 0;
			}
		}
		else if (b[i].second == 'K')
		{
			int beg = 0, end = l;
			int mid = (beg+end)/2;
			int tmp;

			while (beg<=end)
			{
				tmp = get_bit(mid);
				if (tmp==b[i].first)
				{
					if (compress[mid])
						break;
					else end=mid-1;
				}
				else if (tmp < b[i].first)
					beg=mid+1;
				else end = mid-1;

				mid = (beg+end)/2;
			}

			if (tmp!=b[i].first)
				printf("invalid\n");
			else printf("%d\n",a[mid]);
		}
		else if (b[i].second == 'C')
		{
			k = css[b[i].first];
			int tmp = get_bit(k);
			if (compress[k] == 1)
				tmp--;
			printf("%d\n",tmp);
		}
	}
	return 0;
}