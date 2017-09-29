#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
//#include <bits/stdc++.h>
using namespace std;

#define M 1010
#define N 37
#define in "in.in"
#define out "out.in"
#define mp make_pair
#define si(a) scanf("%d",&a)
#define sc(a) scanf("%c",&a)
#define sst(s) scanf("%s",s)
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
#define si2(a,b) scanf("%d%d",&a,&b)
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rep_(i,a,b) for(int i=a;i>=b;--i)
#define Set(a,b) memset(a,b,sizeof a)
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define All(s) s.begin(),s.end()
#define Sz(a) a.size()

#define lli long long int
#define llu unsigned long long
#define Mit map<int ,int>::iterator
#define Sit set<char>::iterator
#define Vi vector<int>
#define Si set<lli>

#define Vname(A) #A

#define Bug puts("bug")

int geti(){ int x; si(x); return x; }
int gcd(int a, int b){ return (a == 0) ? b : (b == 0) ? a : (a%b == 0) ? b : gcd(b, a%b); }

int div_str(char s[], int a){
 int y = 0, ln = strlen(s);
 rep(i, 0, ln) y = ((y * 10) + (s[i] - '0')) % a;
 return y;
}

int dx[] = { -1, -1, 1, 1, -2, -2, 2, 2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
int m;
char s1[(int)1e6 + 5];
int main()
{
 //read(in);
 //write(out);
 int sum, mx, k, r, l;
 while (si(m) > 0 && m)
 {
  scanf(" %[^\n]s", s1);
  int cont[300] = {}, ln = strlen(s1);
  sum = k = r = l = 0;
  mx = -1;
  while (s1[r])
  {
   if (cont[s1[r]] == 0)k++;
   sum++, cont[s1[r]]++;
   while (k > m )
   {
    sum--;
    cont[s1[l++]]--;
    if (cont[s1[l - 1]] == 0)k--;
   }
   r++;
   if (sum > mx)mx = sum;
  }
  if (sum > mx)mx = sum;
  printf("%d\n", mx);
 }
 return 0;
}