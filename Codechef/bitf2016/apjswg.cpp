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

int a[100005];
int bit[100005];

int get_sum(int x){
	int sum = 0;
	while (x>0){
		sum += bit[x];
		x -= x&(-x);
	}
	return sum;
}

void set_bit(int i, int val){
	while (i < 100001){
		bit[i] += val;
		i += i&(-i);
	}
}

int main()
{
	int T;
	get(T);
	for (int __rep = 1; __rep <=T; __rep++)
	{
		int n;
		get(n);

		memset(bit,0,sizeof bit);

		for (int i=0; i<n; i++){
			get(a[i]);
		}

		bool flag = true;
		int ans = 0;

		for (int i=n-1; i>=0; i--){
			int s = get_sum(a[i]);
			if (s>2){
				flag = false;
				break;
			}
			ans += s;
			set_bit(a[i],1);
		}

		if (flag)
			printf("%d\n", ans);
		else
			printf("Not Allowed\n");
	}
	return 0;
}