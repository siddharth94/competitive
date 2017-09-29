#include <bits/stdc++.h>
using namespace std;

#define R(i,a,b) for(LL i=a;i<b;i++)
#define RE(i,a,b) for(LL i=a;i<=b;i++)
#define RR(i,a,b) for(LL i=a;i>b;i--)
#define RRE(i,a,b) for(LL i=a;i>=b;i--)
#define F(i,n) for(LL i=0;i<n;i++)
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

struct node
{
	LL type;
	LL time;
	LL speed;
	LL cycl;

	node()
	{
		type = time = speed = cycl = 0;
	}

}query[100005];

LL dist[50005];
LL time_incr[50005];
LL speed[50005];

LL stree[400005];
LL n,q;

bool cmp(node a, LL val)
{
	return a.time < val;
}

LL query_stree(LL root, LL s, LL e, LL x)
{
	if (s<=x && e>=x && stree[root] != -1)
		return stree[root];

	LL mid = (s+e)>>1;
	if (x <= mid)
		return query_stree(root*2, s, mid, x);
	else
		return query_stree(root*2+1, mid+1, e, x);
}

void update(LL root, LL s, LL e, LL qs, LL qe, LL val)
{
	LL mid = (s+e)>>1;

	if (s==qs && e==qe)
	{
		if (stree[root] != -1 && speed[stree[root]] < speed[val])
			stree[root] = val;
		else if (stree[root] == -1)
		{
			update(root*2, s, mid, qs, mid, val);
			update(root*2+1, mid+1, e, mid+1, qe, val);
		}
		else if (speed[stree[root]] > speed[val])
		{
			LL cycl = stree[root];
			LL lead = val;

			LL t_idx;

			LL t_overtake = ceil(((dist[lead]-dist[cycl] + time_incr[cycl]*speed[cycl] - time_incr[lead]*speed[lead])*1.0)/(speed[cycl]-speed[lead]));	
			node* ind = lower_bound(query, query+q, t_overtake, cmp);
			t_idx = ind-query;

			stree[root] = -1;
			if (t_idx <= qe && qs <= t_idx-1)
			{
				update(root, s, e, qs, t_idx-1, lead);
				update(root, s, e, t_idx, qe, cycl);
			}
			if (t_idx > qe)
			{
				update(root, s, e, qs, qe, lead);
			}


		}

		return;
	}

	if (qe <= mid)
	{
		if (stree[root] != -1)
		{
			stree[root*2] = stree[root];
			stree[root*2+1] = stree[root];
			stree[root] = -1;
		}
		update(root*2, s, mid, qs, qe, val);
	}
	else if (qs > mid)
	{
		if (stree[root] != -1)
		{
			stree[root*2] = stree[root];
			stree[root*2+1] = stree[root];
			stree[root] = -1;
		}
		update(root*2+1, mid+1, e, qs, qe, val);
	}
	else
	{
		if (stree[root] != -1)
		{
			stree[root*2] = stree[root];
			stree[root*2+1] = stree[root];
			stree[root] = -1;
		}
		update(root*2, s, mid, qs, mid, val);
		update(root*2+1, mid+1, e, mid+1, qe, val);
	}
}

int main()
{
	getll(n);
	getll(q);

	F(i,400005)
	{
		stree[i] = 1;
	}

	F(i,q)
	{
		getll(query[i].type);
		getll(query[i].time);

		if (query[i].type == 1)
		{
			getll(query[i].cycl);
			getll(query[i].speed);
		}
	}

	F(i,q)
	{
		if (query[i].type == 1)
		{
			LL cycl = query[i].cycl;
			LL time = query[i].time;

			dist[cycl] += speed[cycl]*(time - time_incr[cycl]);
			time_incr[cycl] = time;
			speed[cycl] = query[i].speed;

			LL lead = query_stree(1, 0, q-1, i);
			if (speed[lead] < speed[cycl])
			{
				LL t_idx;
				while (speed[lead] < speed[cycl])
				{
					LL t_overtake = ceil(((dist[lead]-dist[cycl] + time_incr[cycl]*speed[cycl] - time_incr[lead]*speed[lead])*1.0)/(speed[cycl]-speed[lead]));
					node* ind = lower_bound(query, query+q, t_overtake, cmp);
					t_idx = ind-query;
					if (t_idx != q)
					{
						LL nlead = query_stree(1, 0, q-1, t_idx);
						if (lead == nlead)
							break;
						else
							lead = nlead;
					}
					else
						break;
				}
				if (t_idx != q)
					update(1, 0, q-1, t_idx, q-1, cycl);
			}
		}
		else
		{
			LL lead = query_stree(1, 0, q-1, i);
			printf("%lld\n", dist[lead] + speed[lead]*(query[i].time - time_incr[lead]));
		}
	}
	return 0;
}