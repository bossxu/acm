#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
ll dp[2000005];
ll f[1000005];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=2000000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
  f[0] = 0;
  f[1] = 1;
  for(int i = 2;i<=1000000;i++)
  {
    f[i] = (f[i-2] + f[i-1] )%(mod-1);
  }
}
ll quick(ll a, ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
ll C(int n,int k)
{
  ll ans = dp[n];
  ans = ans*quick(dp[n-k]*dp[k]%mod,mod-2)%mod;
}

int main()
{
  int n,m;
  init();
  while(cin>>n>>m)
  {
    cout<<C(n,m)<<endl;
    cout<<(254*8+2*28)*quick(C(n,m),mod-2)%mod+1<<endl;
  }

  return 0;
}
