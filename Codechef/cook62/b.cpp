#include<bits/stdc++.h>

using namespace std;

#define s(n) scanf("%lld", &n)

int main()
{
    long long int T, L, R, n, ans;
    s(T);
    while(T--)
    {
        ans=0;
        s(L);
        s(R);
        if(L==1)
            ans++;
        n=1;
        for(long long int i=1;i<=log2(R);i++)
        {
            n=n*2;
            for(long long int j=1;(n*j)<=R;j=j*3)
                if((n*j)>=L)
                    ans++;
        }
        printf("%lld\n", ans);
    }
}
