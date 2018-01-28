#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int ret(int n,int a)
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
    int i;
    char c[200005];
    ll ao[200005];
       for(i=0;i<20005;i++)
       {
           ao[i]=ret(i,10);
       }
   while (scanf("%s",c)!=EOF)
   {
       int i=0,j=0;
      // memset(dp,0,sizeof(dp));
       ll dp=c[i]-'0';
       ll sum=0;
       for(i=1;i<strlen(c);i++)
       {
           if(c[i]!='0'){
                dp=(dp+(i+1)*(c[i]-'0'))%mod ;
               sum = (sum + dp%mod * ao[strlen(c)-i]%mod);
           }
           else 
           {sum = (sum + dp%mod * ao[strlen(c)-i-1]%mod);}
       }
       
      /* for(i=0;i<strlen(c);i++)
       {
        sum = (sum + dp[i]%mod * ao[strlen(c)-i-1]%mod);
       }*/
          printf("%lld\n",sum%mod);
   }
    return 0;
}