#include <bits/stdc++.h>
using namespace std;
 
int sieve[100005];
int prime[10000];
 
void make_sieve()
{
    int j=0;
    long long size = 100000;
    memset(sieve,0,sizeof(sieve));
    for (int i=2; i<size; i++)
    {
        if (sieve[i]!=0)
        continue;
        long long int k=i;
        long long int p=i*k;
        prime[j++] = i;
        while (p < size)
        {
            sieve[p]=1;
            if (i&1)
                k+=2;
            else k++;
            p = i*k;
        }
    }
    // cout << j << endl;
    return;
}
 
int main()
{
    memset(prime,-1,sizeof(prime));
    make_sieve();
    int j=0;    
    while (prime[j]!=-1)
        cout << prime[j++] << ",";
    cout << endl << j << endl;
    return 0;
}