#include<math.h>
#include<stdio.h>
#include<string.h>
typedef long long ll;
#define mod 1000000007
int main()
{
    ll a[6];
    int i;
    ll t;
    while(scanf("%lld%lld",&a[0],&a[1])==2)
    {
       for(i=2;i<6;i++)
       {
           a[i]=(a[i-1]-a[i-2])%mod;
       }
       scanf("%lld",&t);
       t=(t-1)%6;
       if(a[t]>=0) printf("%lld\n",a[t]%mod);
       else printf("%lld\n",mod-(-a[t])%mod);
    }
    return 0;
}
