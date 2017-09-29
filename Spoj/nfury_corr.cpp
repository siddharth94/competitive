     /*
    NISHANT GUPTA
    MNNIT ALLAHABAD
    */
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <algorithm>
    #include <stdlib.h>
    #define max(x,y) x>y?x:y
    #define min(x,y) x<y?x:y
    #define abso(x) x<0?(-x):x
    #define rep(i,n) for(i=0;i<n;i++)
    #define rev(i,n) for(i=n;i>=0;i--)
    #define getcx getchar_unlocked
    using namespace std;
    inline void inp( int &n )
    {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
    }
    int main()
    {int i,j,k=0;int a[1001]={0};
    for(i=1;i*i<=1000;i++)a[i*i]=1;
    for(i=1;i<=1000;i++)
    {
    if(a[i])continue;
    else
    {int min=1000;
    for(j=1;j<=(i/2);j++)
    {
    if((a[j]+a[i-j])<min)min=a[j]+a[i-j];
    }
    a[i]=min;
    //k+=a[i];
    }
    }
    //printf("%d\n",k);
    int t,n;
    inp(t);
    while(t--){
    inp(n);
    printf("%d\n",a[n]);
    }
    return 0;
    } 