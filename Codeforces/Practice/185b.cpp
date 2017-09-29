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
#define endl '\n' 

int main()
{
	std::ios::sync_with_stdio(false);
	int s;
	cin >> s;

	int a,b,c;
	cin >> a >> b >> c;

	if (a==0 && b==0 && c==0){
		cout << "0.0 0.0 0.0" << endl;
	}
	else {
		double x,y,z;

		x = a*s*1.0/(a+b+c);
		y = b*s*1.0/(a+b+c);
		z = c*s*1.0/(a+b+c);
		std::cout << std::fixed;
	    std::cout << std::setprecision(12);
		cout << x << " " << y << " " << z << endl;
	}

	return 0;
}