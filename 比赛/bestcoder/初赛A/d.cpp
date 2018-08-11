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
ll dp[2005][1005][2];
ll inv[3000];
void init()
{
  dp[1][0][0] = 1;
  for(int i = 2;i<=2000;i++)
  {
    dp[i][0][0] = 1;
    for(int j = 1;j<i;j++)
    {
      dp[i][j][1] = dp[i-1][j-1][0];
      dp[i][j][0] = (dp[i-1][j-1][0]+dp[i-1][j-1][1])%mod;
    }
  }
  inv[0] = 1;
  for(int i = 1;i<=2000;i++)
  {
    inv[i] = i*inv[i-1]%mod;
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
ll C(int n,int m)
{
  ll ans = inv[n];
  ll fenmu = inv[m]*inv[n-m]%mod;
  return ans*quick(fenmu,mod-2)%mod;
}
int main()
{
  int n,k;
  clr(dp,0);
  init();
  while(cin>>n>>k)
  {
    ll ans = 0;
    int op = 2*n;
    for(int i = 1;i<=n;i++)
    {
      cout<<i<<" "<<dp[op][i][0]<<" "<<dp[op][i+1][0]<<endl;
      ans += quick(k,i)*(dp[op][i][0]- dp[op][i+1][0])*quick(2,i)*C(n,i)*inv[op-2*i];
    }
    ans%=mod;
    ans = (ans+mod)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
