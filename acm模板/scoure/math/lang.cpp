#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
const int N = 1e6+5;
// 这个是一个用拉格朗日插值求自然数幂和的板子
ll dp[N],n,k,q[N],p[N],f[N];
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
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=1000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll solve()
{
  ll ans = 0;
  p[0] = q[k+3] = 1;
  for(int i = 1;i<=k+2;i++) p[i] = p[i-1]*(n-i)%mod;
  for(int i = k+2;i>=1;i--) q[i] = q[i+1]*(n-i)%mod;
  for(int i = 1;i<=k+2;i++) ans+=((k-i+2)%2?(-1):1)*f[i]*(p[i-1]*q[i+1]%mod)%mod *quick(dp[i-1]*dp[k+2-i]%mod,mod-2)%mod;
  return (ans%mod+mod)%mod;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  while(cin>>n>>k)
  {
    f[0] = 0;
    for(int i = 1;i<=2*n;i++)
    {
      f[i] = f[i-1] + quick(i,k);
      f[i]%=mod;
    }
    cout<<solve()<<endl;
  }

  return 0;
}
