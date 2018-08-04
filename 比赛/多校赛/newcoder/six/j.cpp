#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll unsigned
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;

ll a,b,c;
int n;
ll x,y,z;

ll gcd( ll o, ll p)
{
  return p ==0?o:gcd(p,o%p);
}
ll tang()
{
  ll t;
  x ^= (x<<16);
  x ^= (x>>5);
  x ^= (x<<1);
  t = x;
  x = y;
  y = z;
  z = x^y^t;
  return z;
}
int dp[2];
int main()
{
  int t;
  scanf("%d",&t);
  int tot = 0;
  while(t--)
  {
    dp[1] = dp[0] = 1;
    scanf("%d%u%u%u",&n,&a,&b,&c);
    x = a,y = b,z = c;
    ll pre = 1,now;
    //int op = 1;
    ll k = 1;
    ll l = 1;
    long long maxn = 0;
    //int ko[2][2];
    for(int i = 0;i<n;i++)
    {
      now = tang();
      if(now > l)
      {
         k = gcd(now,l);
         l = now;

      }

    }
    //maxn = max(maxn,1LL*shu[0][i]/gcd(shu[1][j],shu[0][i])*shu[1][j]);
    printf("Case #%d: ",++tot);
    printf("%lld\n",maxn);
  }
  return 0;
}
