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

int main()
{
	char dir;
	string keys = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string s;
	map <char,int> mapp;

	int l = keys.length();

	F(i,l)
	{
		mapp[keys[i]] = i;
	}

	scanf("%c",&dir);
	cin >> s;
	int len = s.length();
	int m;

	if (dir == 'R')
		m = -1;
	else if (dir == 'L')
		m = 1;

	F(i,len)
	{
		s[i] = keys[mapp[s[i]] + m];
	}

	cout << s << endl;

	return 0;
}