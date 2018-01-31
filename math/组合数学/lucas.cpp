#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn = 1e5+7;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
//用于解 C(n,m) n,m特别大的情况
//但是要求的是为素数
int mod;
ll dp[maxn+5];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=mod;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll quick(ll a , ll n)
{
  ll res = 1;
  while(n)
  {
     if(n&1) res = res*a%mod;
     a = (a%mod)*(a%mod)%mod;
     n/=2;
  }
  return res;
}
ll lucas(ll n, ll m)
{
  ll ret = 1;
  while(n && m)
  {
    ll a = n%mod, b = m%mod;
    if(a<b) return 0;
    ret = ((ret * dp[a])%mod*quick(dp[b]*dp[a-b]%mod,mod-2))%mod;
    n/=mod;
    m/=mod;
  }
  return ret;
}

int main()
{
   int t,p;
   ll a,b;
   cin>>t;
   while(t--)
   {
     cin>>a>>b>>p;
     mod = p;
     init();
     cout<<lucas(a+b,b)<<endl;
   }
  return 0;
}
