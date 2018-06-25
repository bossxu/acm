#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int mod = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
ll dp[1005];
ll quick(ll a,ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b&1)
    {
      ans = ans*a%mod;
    }
    a = a*a%mod;
    b/=2;
  }
  return ans;
}
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=1000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  init();
  while(cin>>n)
  {
    ll ans = 0;
    int k = n-1;
    for(int i = 0;i<=k/4;i++)
    {
      ans += ((dp[k]*quick(dp[2*i]*dp[k-2*i]%mod,mod-2))%mod)*((dp[k-2*i]*quick(dp[2*i]*dp[k-i*4]%mod,mod-2))%mod)%mod;
    }
    cout<<(ans%mod)<<endl;
  }
  return 0;
}
