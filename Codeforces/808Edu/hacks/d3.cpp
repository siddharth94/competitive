#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("in.txt","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>

vector<int> G[2*100000+5];
int A[100000+5];
int main(){
//    fre;
    map<LL,int>L,R;
    LL sl = 0,sr = 0;
    int N;
    cin>>N;
    for(int i=1;i<=N;++i){
        scan(A[i]);
        R[A[i]]++;
        sr += A[i];
    }
    int ans = 0;
    for(int i=1;i<N;++i){
        sl += A[i];
        sr -= A[i];
        L[A[i]]++;
        R[A[i]]--;
        LL d = sl - sr;
        if((abs(d))%2==1)continue;
        d /= 2;
        ans |= (d==0);
        if(d < 0){
//            cerr<<i<<' '<<d<<endl;
            ans |= (R[-d] > 0);
        }
        else{
            ans |= (L[d] > 0);
        }
    }
    printf(ans?"YES":"NO");
}