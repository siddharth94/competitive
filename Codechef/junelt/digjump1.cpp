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
 
void getc(char &x)
{
    register char c = gc();
    for(;(c<48 || c>57);c = gc());
    x = c;
}
 
struct node
{
    int index;
    int val;
    bool visited;
    int level;
}graph[1000005];

int mark[11];

int bsf(queue <node> q, int n, int level, vector <vector <int> > adj_list)
{
    while ((q.front()).level == level-1 && !q.empty())
    {
        node tmp = q.front();
        if (tmp.index != 0 && !graph[tmp.index - 1].visited)
        {
            if (graph[tmp.index - 1].index == n-1)
                return level;
            graph[tmp.index - 1].level = level;
            graph[tmp.index - 1].visited = true;
            q.push(graph[(tmp.index)-1]);
        }
        if (tmp.index != n-1 && !graph[tmp.index + 1].visited)
        {
            if (graph[tmp.index + 1].index == n-1)
                return level;
            graph[tmp.index + 1].level = level;
            graph[tmp.index + 1].visited = true;
            q.push(graph[(tmp.index)+1]);
        }
        if (mark[tmp.val] != 1)
        {  
            mark[tmp.val] = 1;
            for (vector <int> :: iterator it = adj_list[tmp.val].begin(); it != adj_list[tmp.val].end(); ++it)
            {
                if (!(graph[(*it)].visited))
                {
                    if ((*it) == n-1)
                        return level;
                    graph[(*it)].level = level;
                    graph[(*it)].visited = true;
                    q.push(graph[(*it)]);
                }
            }
        }
        q.pop();
    }
    if (q.empty())
        return level-1;
    return bsf(q,n,level+1,adj_list);
}
 
int main()
{
    int n=0;
    vector <vector <int> > adj_list(10);
    char a1 = gc();
    for(;(a1<48 || a1>57);a1 = gc());
    while (a1>47 && a1<58)
    {
        int a = a1-'0';
        graph[n].index = n;
        graph[n].val = a;
        graph[n].visited = false;
        graph[n].level = -1;
        adj_list[a].push_back(n);
        n++;
        a1=gc();
    }
    queue <node> q;
    graph[0].level = 0;
    graph[0].visited = true;
    q.push(graph[0]);
    printf("%d\n",bsf(q,n,1,adj_list));
    return 0;
} 