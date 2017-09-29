#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define mp(a,b) make_pair(a,b)
#define pii pair <int, int>
#define LL long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define get(n) scanf("%d",&n);

string name[200009];
int p[100005];
string handle[100005];
string big;

string sm(string a, string b)
{
	if (a.compare(b) < 0){
		big = b;
		return a;
	}
	else{
		big = a;
		return b;
	}
}

int main()
{
	int n;
	get(n);

	int m = n<<1;

	F(i,m)
		// scanf("%s",name[i]);
		cin >> name[i];

	F(i,n)
		get(p[i]);

	string small = sm(name[(p[0]-1)*2], name[((p[0]-1)*2)+1]);
	handle[0] = small;

	for (int i=1; i<n; i++)
	{
		int k = p[i];

		string small = sm(name[(p[i]-1)*2], name[((p[i]-1)*2)+1]);

		if (handle[i-1].compare(small)<0)
		{
			handle[i] = small;
			continue;
		}
		else if (handle[i-1].compare(big)<0)
		{
			handle[i] = big;
		}
		else 
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}