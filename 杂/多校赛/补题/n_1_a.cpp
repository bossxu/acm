#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
// 题解是把这个拆分成几个两条路，把这个区域分成三个区域
// 一个是0,一个是1，一个是2
//所以这里的是求两条路不交叉的情况一共有多少种
//比赛的时候更本想不到，我一开始还以为是一个dp。现在可以预估有些题目不是一些简单的套路所能解决的
//很多的问题已经是要通过转换来解决
//通过这些时候多学点把
ll dp[3005];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=3000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll quick(ll a,ll b)
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
int main()
{
  int n,m;
  init();
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(cin>>n>>m)
  {
    ll ans = dp[n+m]*quick(dp[n]*dp[m]%mod,mod-2)%mod;
    ans = ans*ans%mod;
    ll res = dp[n+m]*quick(dp[n-1]*dp[m+1]%mod,mod-2)%mod;
    res = (res*dp[n+m]%mod)*quick(dp[n+1]*dp[m-1]%mod,mod-2)%mod;
    ans -= res;
    ans = (ans%mod+mod)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
