#include <bits/stdc++.h>
using namespace std;

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define LL long long
#define gc getchar_unlocked

void get(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

class node
{
public:
	string val;
	node *left;
	node *right;
	node()
	{
		left = NULL;
		right = NULL;
	}
};

int find_closing_bracket(string s,int begin)
{
	int c=0;
	int len = s.length();
	while (begin < len)
	{
		if (s[begin] == '(')
			c++;
		else if (s[begin] == ')')
			c--;
		if (c==0)
			return begin;
		begin++;
	}
}

void tree(node *v)
{
	int val_len = v->val.length();
	if (val_len == 1)
	{
		cout << v->val;
		return;
	}
	else
	{
		int end=-1;
		v->left = new node;
		v->right = new node;
		if (v->val[1]>='a' && v->val[1]<='z')
		{
			v->left->val = v->val[1];
		}
		else
		{
			end = find_closing_bracket(v->val,1);
			v->left->val = v->val.substr(1,end);
		}
		if (v->val[val_len-2]>='a' && v->val[val_len-2]<='z')
		{
			v->right->val = v->val[val_len-2];
		}
		else
		{
			if (end != -1)
				v->right->val = v->val.substr(end+2,val_len-end-3);
			else
				v->right->val = v->val.substr(3,val_len-4);
		}
		if (end != -1)
			v->val = v->val[end+1];
		else
			v->val = v->val[2];
	}
	tree(v->left);
	tree(v->right);
	cout << v->val;
}

// void print(node v)
// {
	
// 		cout << v.val;
// }

int main()
{
	int T;
	get(T);
	while (T--)
	{
		string pol;
		cin >> pol;
		node root;
		root.val = pol;
		tree(&root);
		printf("\n");
		// print(root); 
	}
	return 0;
}