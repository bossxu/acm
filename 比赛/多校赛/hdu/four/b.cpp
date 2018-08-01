#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
ll quick(ll a, ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res *a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
ll dp[100005];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=100000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll C(int n,int m)
{
  ll res = dp[n];
  ll fenmu = quick((dp[n-m]*dp[m])%mod,mod-2);
  return res*fenmu%mod;
}
int ans[1000];
ll T(int n,int m)
{
  if(m == 0) return 1;
  if(n == m) ans[n]++;
  if(n == m) return quick(2,n);
  return (T(n-1,m-1)+T(n-1,m))%mod;

}
int main()
{
  int t;
  cin>>t;
  init();
  while(t--)
  {
    int n,m;
    while(cin>>n>>m)
    {
      // ll ans = 0;
      // for(int i = 1;i<=m;i++)
      // {
      //   ans = (ans + C(n,i))%mod;
      // }
      // cout<<ans+1<<" ";
      // cout<<C(n,m)<<endl;
      clr(ans,0);
      cout<<T(n,m)<<" -- ";
      cout<<C(n,m)<<endl;
      for(int i = 1;i<=m;i++)
      {
        cout<<i<<":"<<ans[i]<<"  ";
      }
      cout<<endl;
    }
  }
  return 0;
}
