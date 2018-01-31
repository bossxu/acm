//卢卡斯定理
//用于求组合数 当那两个玩意特别大的时候
//注意啊，我这里是用快速幂来求乘法逆元
//他的要求为 mod 必须为素数
//好像也没有如果，不然好像还真不知道
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
