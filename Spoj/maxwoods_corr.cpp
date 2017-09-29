#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v[205][205],N,M;
int dp[2][205][205];

int init(){
  
}

int solve(){
	for(int i=N;i>0;i--){
		for(int j=1;j<=M;j++)
			if(v[i][j])
				dp[0][i][j]=max(dp[0][i][j-1], dp[1][i+1][j]) + v[i][j] -1 ;	
		for(int j=M;j>0;j--)
			if(v[i][j])
				dp[1][i][j]=max(dp[1][i][j+1], dp[0][i+1][j]) + v[i][j] -1;	
	}
	cout << dp[1][1][1] << endl;
}

int input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		string a;
		cin >> a;
		for(int j=1;j<=M;j++)
			if(a[j-1]=='T') 
				v[i][j]=2;
			else if (a[j-1]=='0') 
				v[i][j]=1;
			else 
				v[i][j]=0;
	}
	memset(dp, 0, sizeof(dp));
	return 0;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		input();
		solve();
	}
	return 0;
}