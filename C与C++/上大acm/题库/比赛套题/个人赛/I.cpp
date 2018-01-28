#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll ret(int n,int a)
{
    ll c=1;
    while(n!=0)
    {
       if(n%2==1) c=(c%mod)*(a%mod) %mod;
       n/=2;
       a=(a%mod)*(a%mod)%mod;
    }
    return c;
}
int main()
{
   char c[200005];
   ll po[200005];
   ll co;
   while (scanf("%s",c)!=EOF)
   {
       int i=0,j=0;
       co=c[0]-'0';
       ll sum= co * ret(strlen(c)-1,10) %mod;
       for(i=1;i<strlen(c);i++)
       {
               co=(co+(i+1)*(c[i]-'0'))%mod ;
               sum = (sum + co *ret(strlen(c)-1-i,10)%mod)%mod;
       }
          printf("%lld\n",sum%mod);
   }
    return 0;
}