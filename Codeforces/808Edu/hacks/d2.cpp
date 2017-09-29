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

int main(){
	int n,k;
	cin>>n;
	map<ll,int> nak1,nak2;
	ll a[n+1];
	ll sum=0,cum[n+1];
	REP(i,1,n){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<"NO"<<endl;
		return 0;
	}
	REP(i,1,n){
		nak2[a[i]]+=1;
		nak1[a[i]]=0;
	}
	cum[0]=0;
	REP(i,1,n)
		cum[i]=cum[i-1]+a[i];
	REP(i,1,n){
		nak1[a[i]]++;
		nak2[a[i]]--;
		ll sum1=cum[i],sum2=sum-sum1;
		//cout<<sum1<<" "<<sum2<<endl;
		if(sum1>sum2){
			if((sum1-sum2)%2==0 && nak1[(sum1-sum2)/2]>=1){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		else if(sum1<sum2){
			//cout<<nak2[(sum2-sum1)/2]<<" "<<!(sum2-sum1)%2<<endl;
			if((sum2-sum1)%2==0 && nak2[(sum2-sum1)/2]>=1){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		else{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}