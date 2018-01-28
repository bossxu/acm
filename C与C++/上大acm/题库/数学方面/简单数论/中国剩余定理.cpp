#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
/*
注意使用的条件，首先必须除数互质

*/
ll  gcd(ll  a,ll  b)
{
   return a%b==0?b:gcd(b,a%b);
}
void exGcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return;
    }
    exGcd(b,a%b,y,x);
    y-=a/b*x;
}
int main()
{
   int T;
   cin>>T;
   ll chu[7],yu[7];
   ll ch[7],s[7];
   
   while(T--)
   {
     int n;int item=1;
     scanf("%d",&n);
     int i,j;
     for(i=1;i<=n;i++)
     {
         scanf("%lld",&chu[i]);
     }
     for(i=1;i<=n;i++)
     {
         scanf("%lld",&yu[i]);
     }
       ll ans=0;
       ll mod = 1;
       for(i=1;i<=n;i++)
       {
           mod=mod/gcd(mod,chu[i])*chu[i];
       }
     for(i=1;i<=n;i++)
     {
        ll c=1;
       for(j=1;j<=n;j++)
       {
           if(i==j) continue;
           else c =c/gcd(c,chu[j])*chu[j] ;
       }  

       if(yu[i] % gcd(c,chu[i]) != 0) item=0;
          yu[i]/=gcd(c,chu[i]);
          ll x,y;
           exGcd(c,chu[i],x,y); 
           while(x<0)//牛逼，我这都没想到
         {
             x+=chu[i];
             y-=c;
         }
           ch[i]=x%mod*c; 
     }
       for(i=1;i<=n;i++)
       {
           ans+=ch[i]*yu[i]%mod;
       }
       ans%=mod;
     printf("%lld\n",ans);
   }
    system("pause");
    return 0;
}