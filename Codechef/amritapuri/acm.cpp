#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define gc getchar_unlocked
#define pc putchar_unlocked

ll pow(ll num, ll pow, ll mod)
{
    ll test;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = (test * num) % mod;
        num = (num * num) % mod;
    }

    return test;

}

inline void get(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{
	ll a[20005], Q, m, L, n;
	char G[20005];
	scanf("%s\n",G);
	get(Q);
	n=strlen(G);
	for(int i=0;i<n;i++)
		a[i]=int(G[i])-48;
	while(Q--)
	{
		get(m);
		get(L);
		static ll i, j, temp, ans, t;
		while(i<n && j<n)
		{
			t=((temp*10)%m + a[j])%m;
			if(t<L)
				j++;			
			while(t==L && i<=j)
			{
				ans++;
				t=((t-(a[i]*pow(10,(j-i),m))%m)+m)%m;
				if(i!=j) i++;
			}
			while(t>L && i<=j)
			{
				//remove i;
				t=((t-(a[i]*pow(10,(j-i),m))%m)+m)%m;
				if(i!=j) i++;
			}
			temp=t;
			cout << temp;
		}
		printf("%lld\n",ans);		
	}
	return 0;
}
