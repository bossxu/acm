#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 998244353;
const double eps = 1e-6;
//这道题在比赛的时候我没做出来
//很难受，那时候容斥没想出来,这题只能容斥，不能母函数，会t；
//组合数学学的还是不行
//反演的题，G(n)表示有n个数不满足这种情况
ll dp[200005];
ll inv[200005];
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
void init()
{
  dp[1] = 1;
  dp[0] = 1;
  inv[0] = 1;
  for(int i = 1;i<=200000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
    inv[i] = quick(dp[i],mod-2);
  }
}
ll C(int n,int m)
{
  if(n == m) return 1;
  return (dp[n]*inv[m]%mod)*inv[n-m]%mod;
}
int main()
{
  ios_close;
  int t;
  init();
  cin>>t;
  while(t--)
  {
    int n,m,k;
    cin>>n>>m>>k;
    ll ans = 0;
    int flag = 1;
    int down = k+m-1;
    int up = m-1;
    for(int i = 0;i<=m;i++)
    {
      ans = (ans + flag*C(m,i)*C(down,up)%mod)%mod;
      down -= n;
      if(down < up) break;
      flag *= -1;
    }
    cout << (ans+mod)%mod<<endl;
  }
  return 0;
}
