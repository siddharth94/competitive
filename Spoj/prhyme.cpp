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
	int words;
	int prefixes;
	string min1, min2;
	string minword1, minword2;
	struct node* edge[27];

	node()
	{
		words = 0;
		prefixes = 0;
		F(i,26)
			edge[i] = NULL;
		min1 = min2 = " ";
		minword1 = minword2 = " ";
	}

	void add_word(string word, string fword)
	{
		string n = " ";
		int l = word.length();
		
		if (minword1 == n)
		{
			minword1 = fword;
			min1 = word;
		}
		else if (minword1 > fword)
		{
			minword2 = minword1;
			min2 = min1;
			minword1 = fword;
			min1 = word;
		}
		else if (minword2 == n || minword2 > fword)
		{
			minword2 = fword;
			min2 = word;
		}
		
		if (l == 0)
			words++;
		else
		{
			prefixes++;
			int e = word[l-1]-'a';
			if (edge[e] == NULL)
				edge[e] = new node();
			edge[e]->add_word(word.substr(0,word.length()-1), fword);
		}
	}

	string get_word(string q)
	{
		string n = " ";
		int l = q.length();
		if (l==0 && prefixes > 0)
		{
			if (min1.length()>0)
				return min1;
			else return min2;
		}
		if (l==0 && words>0)
			return n;
		if (edge[q[l-1]-'a']==NULL)
			return min1;
		if (edge[q[l-1]-'a']!=NULL)
		{
			string ans = edge[q[l-1]-'a']->get_word(q.substr(0,l-1));
			if (ans==n)
			{
				if (min1==q)
					return min2;
				return min1;
			}
			return ans+q[l-1];
		}
	}
}trie;

int main()
{
	while (1)
	{
		string s;
		getline (cin,s);
		if (s.length() == 0)
			break;
		trie.add_word(s,s);
	}
	while (1)
	{
		string s;
		getline (cin,s);
		if (s.length() == 0)
			break;
		cout << trie.get_word(s) << "\n";
	}
	return 0;
}