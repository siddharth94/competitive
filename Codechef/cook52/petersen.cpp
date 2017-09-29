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

bool mat[15][15];
char s[100005];
char ans[100005];

bool check(int idx)
{
	ans[0] = (char)(idx+'0');
	int len = strlen(s);
	int i = 1;
	while ( i != len && (mat[idx][s[i]-'A'] || mat[idx][s[i]-'A'+5]))
	{
		if (mat[idx][s[i]-'A'])
			idx = s[i]-'A', ans[i]=s[i]-'A'+'0';
		else if (mat[idx][s[i]-'A'+5])
			idx = s[i]-'A'+5, ans[i]=s[i]-'A'+'5';
		i++;
	}
	if (i==len)
	{
		ans[i] = '\0';
		return true;
	}
	else return false;
}

int main()
{
	int T;
	get(T);
	
	mat[0][1] = mat[0][4] = mat[0][5] = mat[5][7] = mat[5][8] = mat[5][0] = true;
	mat[1][2] = mat[1][0] = mat[1][6] = mat[6][8] = mat[6][9] = mat[6][1] = true;
	mat[2][3] = mat[2][1] = mat[2][7] = mat[7][9] = mat[7][5] = mat[7][2] = true;
	mat[3][4] = mat[3][2] = mat[3][8] = mat[8][5] = mat[8][6] = mat[8][3] = true;
	mat[4][0] = mat[4][3] = mat[4][9] = mat[9][6] = mat[9][7] = mat[9][4] = true;

	for (int __rep = 1; __rep <=T; __rep++)
	{
		scanf("%s",s);
		if (check(s[0]-'A'))
			printf("%s\n",ans);
		else if (check(s[0]-'A'+5))
			printf("%s\n",ans);
		else printf("-1\n");
	}
	return 0;
}