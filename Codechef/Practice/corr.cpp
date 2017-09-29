    #include <bits/stdc++.h>
    using namespace std;
    map<long long int,long long int> maxm;
    long long int max_doll(long long int coins)
    {
    if(coins==0) return 0;
    if(maxm[coins]!=0)
    return maxm[coins];
    else
    {
    maxm[coins] = max(coins,(max_doll(coins/2)+max_doll(coins/3)+max_doll(coins/4)));
    return maxm[coins];
    }
    }
    int main()
    {
    long long int coins;
    while(scanf("%lld", &coins) != EOF)
    printf("%lld\n",max_doll(coins));
    return 0;
    } 