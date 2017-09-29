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
#define get(x) scanf("%d", &x);

// inline void get(int &x)
// {
//     register int c = gc();
//     x = 0;
//     int neg = 0;
//     for(;((c<48 || c>57) && c != '-');c = gc());
//     if(c=='-') {neg=1;c=gc();}
//     for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg) x=-x;
// }

struct node
{
	int win,lose;
	struct node* child[27];

	node()
	{
		win = 0;
		lose = 0;
		F(i,27)
			child[i] = NULL;
	}
}trie;

int insert(string s, struct node* root)
{
	if (!s.length())
	{
		if (root->win)
			return -1; //prev position is losing position as this one is winning position.
		root->lose = 1;
		return 1; // else prev position is winning and this one is losing. 
	}
	int c = s[0]-'a';
	if (root->child[c] == NULL)
		root->child[c] = new node();
	if (root->win == 0)
		root->win = insert(s.substr(1,s.length()-1), root->child[c]);
	if (root->win)
		return 0;
	return 1;
}

int main()
{
	int n,k;
	get(n);
	get(k);

	F(i,n)
	{
		string s;
		cin >> s;
		insert(s, &trie);
	}

	if (trie.win && k%2)
		printf("First\n");
	else
		printf("Second\n");

	return 0;
}