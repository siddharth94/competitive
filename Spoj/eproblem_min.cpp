#include<iostream>
#define LL long long
#define C std::cout<<
void f(LL a){if(a<=2){if(a!=1)C a;return;}LL k=1,p=0;do p++;while((k*=2)<=a);C '2';if(--p!=1)C '(';f(p);a-=k/2;if(a>0){if(p!=1){C ")+";if(a!=1)f(a);else C "2(0)";}else C "+2(0)";}else if(p!=1)C ')';}int main(){LL a;while(std::cin>>a,!std::cin.eof()){C '\n'<<a<<'=';f(a);}}