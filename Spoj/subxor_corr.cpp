#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
inline int getchar_unlocked(){return getchar();}
#endif
inline int in(){int  n = 0, c = getchar_unlocked(),t=0;while(c < '0' || c > '9'){if(c==45)t=1;c = getchar_unlocked();}while(c >= '0' && c <= '9')n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();if(t==0)return n;else return -n;}
 
struct trie_node
{
	int lch,rch,child[2];
}tree[200000];
 
int T,n,k,nd;
void inti()
{
	nd=0;
	for(int i=0;i<200000;i++)
	{
		tree[i].lch=tree[i].rch=0;
		tree[i].child[0]=tree[i].child[1]=-1;
	}
}
 
void insert(int st,int x,int idx)
{
	if(idx==-1)return;
	if(x&(1<<idx))
	{
		if(tree[st].child[1]==-1){
			nd++;
			tree[st].child[1]=nd;
		}
		tree[st].rch+=1;
		insert(tree[st].child[1],x,idx-1);
	}
	else
	{
		if(tree[st].child[0]==-1){
			nd++;
			tree[st].child[0]=nd;
		}
		tree[st].lch+=1;
		insert(tree[st].child[0],x,idx-1);
	}
}
 
int query(int st,int x,int idx)
{
	if(st==-1||idx==-1)return 0;
	int p=x&(1<<idx),q=k&(1<<idx);
	if(q>0)
	{
		if(p==0){
			return tree[st].lch+query(tree[st].child[1],x,idx-1);
		}
		else{
			return tree[st].rch+query(tree[st].child[0],x,idx-1);
		}
	}
	else{
		if(p)query(tree[st].child[1],x,idx-1);
		else query(tree[st].child[0],x,idx-1);
	}	
}
		
int main()
{
	T=in();//scanf("%d",&T);
	while(T--)
	{
		n=in(),k=in();//scanf("%d %d",&n,&k);
		inti();
		insert(0,0,17);
		long long res=0;
		for(int x,pre=0,i=0;i<n;i++)
		{
			x=in();//scanf("%d",&x);
			pre^=x;
			res+=query(0,pre,17);
			insert(0,pre,17);
		}
		printf("%lld\n",res);	
	}
	return 0;
} 