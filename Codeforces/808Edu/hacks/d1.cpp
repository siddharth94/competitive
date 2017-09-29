#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ull, ull> puu;

#define inf (0x3f3f3f3f)
#define lnf (0x3f3f3f3f3f3f3f3f)
#define eps (1e-9)
#define fi first
#define se second

//--------------------------

const ll mod = 1000000007;
const int maxn = 100010;

int n;
ll a[maxn];
ll pre;
ll suf;
ll sum;
ll cha;
map<ll, int> pres;
map<ll, int> sufs;


void solve() {
    cin >> n;
    pre = 0;
    sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sufs[a[i]]++;
    }
    bool flag = false;
    for(int i = 0; i < n - 1 && !flag; i++) {
        pre += a[i];
        suf =  sum - pre;
        sufs[a[i]]--;
        pres[a[i]]++;
        if(suf > pre) {
            cha = suf - pre;
            if(cha & 1)continue;
            if(sufs[cha / 2 ] > 0)flag = true;
        } else if(suf == pre) {
            flag = true;
        } else {
            cha = pre - suf;
            if(cha & 1)continue;
            if(pres[cha / 2] > 0)flag = true;
        }
    }
    if(flag)puts("YES");
    else puts("NO");
}

int main() {

    // iostream::sync_with_stdio(false);
    solve();
    return 0;
}