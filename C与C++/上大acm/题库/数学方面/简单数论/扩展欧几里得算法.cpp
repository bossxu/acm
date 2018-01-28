#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
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
  ll a,b;
  while(cin>>a>>b)
  {
      ll d,e;
      if(gcd(a,b)!=1) printf("sorry\n");
      else
      {
         ll x,y;
         exGcd(a,b,x,y);
         while(x<=0)//牛逼，我这都没想到
         {
             x+=b;
             y-=a;
         }
         printf("%lld %lld\n",x,y);
      }
  }
    return 0;
}