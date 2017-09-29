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

string s[2];
int b;
int marked;
bool visited[2][505];
int n;

bool calc(pii pos)
{
	visited[pos.ft][pos.sd] = true;
	marked++;

	if (marked == b)
		return true;

	int x = pos.ft;
	int y = pos.sd;

	if (!visited[(x+1)%2][y] && s[(x+1)%2][y] == '#')
		return calc(mp((x+1)%2, y));
	else if (y<n-1 && !visited[x][y+1] && s[x][y+1] == '#')
		return calc(mp(x,y+1));
	else return false;

}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		get(n);

		cin >> s[0];
		cin >> s[1];

		b = 0;

		F(i,n)
		{
			if (s[0][i] == '#')
				b++;
			if (s[1][i] == '#')
				b++;
		}

		bool a1, a2;
		a1 = a2 = false;

		for (int i=0; i<n; i++)
		{
			bool flag = false;
			if (s[0][i] == '#')
			{
				memset(visited, 0, sizeof visited);
				marked = 0;
				a1 = calc(mp(0,i));
				flag = true;
			}
			if (s[1][i] == '#')
			{
				memset(visited, 0, sizeof visited);
				marked = 0;
				a2 = calc(mp(1,i));
				flag = true;
			}
			if (flag)
				break;
		}

		if (a1||a2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}