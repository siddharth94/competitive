#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;
 
#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PER(i,a,b) for(int i=b;i>=a;i--)
#define X first
#define Y second
 
 //i/o
#define inp(n) scanf("%d",&n)
#define inpl(n) scanf("%lld",&n)
#define inp2(n,m) inp(n), inp(m)
#define inp2l(n,m) inpl(n), inpl(m)
 
 
//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
#define mp make_pair
typedef long long ll;
typedef pair< pair<ll,ll>,ll > pairs;

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	if(a.X.X<b.X.X)
		return 1;
	else if(a.X.X>b.X.X)
		return 0;
	else if(a.X.X==b.X.X){
		if(a.Y>=b.Y)
			return 1;
		else 
			return 0;
	}
}

int main(){
	int t;
	inp(t);
	while(t--){
		int n,k,m;
		inp2(n,k);
		inp(m);
		vector<pair<pair<int,int>,int> > hor,vert;
		int a,b,c,d;
		rep(i,m){
			inp2(a,b);
			inp2(c,d);
			hor.pb(MP(MP(min(a,c),max(a,c)),abs(a-c)));
			vert.pb(MP(MP(min(b,d),max(b,d)),abs(b-d)));
		}
		sort(vert.begin(),vert.end(),cmp);
		sort(hor.begin(),hor.end(),cmp);
		int prev=(n-k)/2,cnt=0;
		vector<pair<pair<int,int>,int> >::iterator iz,it=vert.begin();
		while(it!=vert.end()){
			// cout<<(*it).X.X<<" "<<(*it).X.Y<<" "<<(*it).Y<<endl;
			it++;
		}
		int flag=1;
		it=hor.begin();
		while(it!=hor.end()){
			int h=(*it).X.X,t=(*it).X.Y;
			if(h>prev+1){
				//cout<<prev<<" "<<h<<endl;
				flag=0;
				break;
			}
			iz=it;
			int z=prev;
			while(iz!=hor.end()){
				if((*iz).X.X>prev+1)
					break;
				z=max((*it).X.Y,z);
				it=iz;
				iz++;
			}
			cnt++;
			prev=z;
			if(prev>=(n-k)/2+k)
				break;
			if(it!=hor.end())
				it++;
		}

		//cout<<"Break"<<endl;
		prev=(n-k)/2;
		it=vert.begin();
		while(it!=vert.end()){
			int h=(*it).X.X,t=(*it).X.Y;
			if(h>prev+1){
				//cout<<"2 "<<h<<" "<<prev<<endl;
				flag=0;
				break;
			}
			iz=it;
			int z=prev;
			while(iz!=vert.end()){
				if((*iz).X.X>prev+1)
					break;
				z=max((*it).X.Y,z);
				it=iz;
				iz++;
			}
			cnt++;
			prev=z;
			if(prev>=(n-k)/2+k)
				break;
			if(it!=vert.end())
				it++;
		}
		
		if(flag)
			cout<<cnt<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}

