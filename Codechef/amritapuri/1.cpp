#include<bits/stdc++.h>
#define gc getchar_unlocked
#define P1 1000000007
#define P2 1000000009
#define ll long long int
using namespace std;
inline void scanint(int &x) { register int c = gc(); x = 0; int neg = 0; for(;((c<48 || c>57) && c != '-');c = gc()); if(c=='-') {neg=1;c=gc();} for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} if(neg) x=-x; }
int Giv[101][101],dp1[150][150][150],dp2[150][150][150];

void scan(int M, int N)
{
	for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
				scanint(Giv[i][j]);
}

void base(int M, int N)
{
			for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
			{
				dp1[i][j][1]=Giv[i][j];
				dp2[i][j][1]=Giv[i][j];
			}
}

int main()
{
	int T;
	scanint(T);
	while(T--)
	{
		int M,N;
		scanint(M);
		scanint(N);

		scan(M,N);
		
		int max=-1000000000;

		base(M,N);

		int G=min(N,M);
		for(int k=3;k<=G;k+=2)
			for(int i=1;i<=M-k+1;i++)
				for(int j=1;j<=N-k+1;j++)
				{
					dp1[i][j][k]=dp1[i][j][(k>>1)]+dp1[i+(k>>1)+1][j+(k>>1)+1][(k>>1)] + Giv[i+(k>>1)][j+(k>>1)];
					dp2[i][j][k]=dp2[i+(k>>1)+1][j][(k>>1)]+dp2[i][j+(k>>1)+1][(k>>1)] + Giv[i+(k>>1)][j+(k>>1)];
					if(max<dp1[i][j][k]+dp2[i][j][k]-Giv[i+(k>>1)][j+(k>>1)])
						max=dp1[i][j][k]+dp2[i][j][k]-Giv[i+(k>>1)][j+(k>>1)];
				}
		for(int i=1;i<=M-1;i++)
			for(int j=1;j<=N-1;j++)
			{
				dp1[i][j][2]=Giv[i][j]+Giv[i+1][j+1];
				dp2[i][j][2]=Giv[i+1][j]+Giv[i][j+1];
				if(max<dp1[i][j][2]+dp2[i][j][2])
					max=dp1[i][j][2]+dp2[i][j][2];
			}
		for(int k=4;k<=G;k+=2)
			for(int i=1;i<=M-k+1;i++)
				for(int j=1;j<=N-k+1;j++)
				{
					dp1[i][j][k]=dp1[i][j][(k>>1)]+dp1[i+(k>>1)][j+(k>>1)][(k>>1)];
					dp2[i][j][k]=dp2[i][j+(k>>1)][(k>>1)]+dp2[i+(k>>1)][j][(k>>1)];
					if(max<dp1[i][j][k]+dp2[i][j][k])
						max=dp1[i][j][k]+dp2[i][j][k];
				}
		printf("%d\n",max);
	}
	return 0;
}
