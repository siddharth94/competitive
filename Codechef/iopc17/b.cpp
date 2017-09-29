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

int stree[4000005];

void build_tree(int root, int ss, int se)
{
	if (ss == se)
	{
		stree[root] = 1;
		return;
	}

	int mid = (ss+se)>>1;
	build_tree(root*2, ss, mid);
	build_tree(root*2+1, mid+1, se);
	stree[root] = stree[root*2] + stree[root*2+1];
	return;
}

void kill(int root, int ss, int se, int x)
{
	if (ss==se && ss==x)
	{
		stree[root] = 0;
		return;
	}

	int mid = (ss+se)>>1;
	if (x <= mid) kill(root*2, ss, mid, x);
	else if (x>mid) kill(root*2+1, mid+1, se, x);

	stree[root] = stree[root*2] + stree[root*2+1];
}

int query(int root, int ss, int se, int x)
{
	if (se == x)
	{
		return stree[root];
	}

	int mid = se/2;

	if (x <= mid)
		return query(root*2, ss, mid, x);
	else
	{
		return query(root*2, ss, mid, mid) + query(root*2+1, mid+1, se, x);
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n,k;
		get(n);
		get(k);
		int mk = k;

		memset(stree, 0, sizeof stree);

		build_tree(1,0,n-1);

		int last_killed = 0; // 0 indexed
		int m = 1;

		if (k>0)
		{
			kill(1,0,n-1, (k%n)-1 );
			last_killed = (k%n)-1;
			m++;
			k = -m*mk;			
		}
		else
		{
			int left = k%n;
			kill(1,0,n-1, n+left );
			last_killed = n+left;
			m++;
			k = m*mk;
		}

		for (int i=1; i<n; i++)
		{
			if (k>0)
			{
				int right = k;
				int alive = stree[1];
				if (right > alive)
					right %= alive;
				if (right == 0)
					right = alive;

				int till_last_killed = query(1, 0, n-1, last_killed);
				int right_alive = alive - till_last_killed;

				if (right <= right_alive)
				{
					kill(1, 0, n-1, right+till_last_killed);
					last_killed = right+till_last_killed;
					m++;
					k = -m*mk; 
				}
				else
				{
					kill(1, 0, n-1, right-right_alive);
					last_killed = right-right_alive;
					m++;
					k = -m*mk;
				}
			}
			else
			{
				int left = abs(k);
				int alive = stree[1];
				if (left > alive)
					left %= alive;

				if (left == 0)
					left = alive;

				int till_last_killed = query(1, 0, n-1, last_killed);
				if (left <= till_last_killed)
				{
					kill(1, 0, n-1, till_last_killed-left);
					last_killed = till_last_killed - left;
					m++;
					k = m*mk;
				}
				else
				{
					left -= till_last_killed;
					kill(1, 0, n-1, alive-left);
					m++;
					k = m*mk;
				}
			}
		}

		cout << last_killed << endl;
	}
	return 0;
}