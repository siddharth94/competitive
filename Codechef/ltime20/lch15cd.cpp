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

struct node
{
	vector <int> arr;
	int sum, x;

	node(){
		sum = x = 0;
	}

	node(node& a)
	{
		copy(a.arr);
		sum = a.sum;
		x = a.x;
	}

	void copy(vector <int> a)
	{
		arr.swap(a);
	}

	node(int n)
	{
		F(i,n)
			arr.pb(0);
		sum = x = 0;
	}
};

int cunt;
int value[66000];
vector <int> adj[66000];
map < vector <int> , int> hash;

void cacl(node dp, int n, int d)
{
	node currn(dp);
	int curr = hash[dp.arr];
	for (int i=0; i<n; i++)
	{
		if (dp.arr[i] == d-1)
			continue;
		else
		{
			dp.arr[i]++;
			if (hash.find(dp.arr) != hash.end())
			{
				adj[curr].pb(hash[dp.arr]);
				dp = currn;
				continue;
			}
			adj[curr].pb(cunt);
			dp.sum++;
			dp.x = dp.arr[n-1];
			F(j,n-1)
				dp.x ^= dp.arr[j];
			value[cunt] = dp.x*dp.sum;
			hash[dp.arr] = cunt++
;			cacl(dp, n, d);
			dp = currn;
		}
	}
}

priority_queue < pii , vector < pii > , greater < pii > > cost;
bool visited[66000];

LL dijkstra(LL b, LL v)
{
	for (LL i=1; i<=v; i++)
	{
		if (cost.size() == 0)
			return -1;

		pii tmp = cost.top();
		visited[tmp.second] = true;

		if (tmp.second == b)
			return tmp.first;

		for (vector < int > :: iterator it = adj[tmp.second].begin(); it != adj[tmp.second].end(); ++it)
		{
			if (visited[(*it)])
				continue;
			else
				cost.push(mp((tmp.first)+value[*it],(*it)));
		}
		while (cost.size() > 0 and visited[(cost.top()).second])
			cost.pop();
	}
	return -1;
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		memset(visited, false, sizeof(visited));
		memset(value, 0, sizeof(value));
		cunt = 0;
		int n,d;
		get(n);
		get(d);
		node dp(n);
		hash[dp.arr] = cunt++;
		value[0] = 0;
		cacl(dp, n, d);
		vector <int> tmp(n,d-1);
		int target = hash[tmp];
		cost.push(mp(0,0));
		visited[0] = true;			
		LL ans = dijkstra(target,cunt);
		cout << ans << endl;
		F(i,65998)
			adj[i].clear();
		hash.clear();
		while (cost.size() > 0)
			cost.pop();
	}
	return 0;
}