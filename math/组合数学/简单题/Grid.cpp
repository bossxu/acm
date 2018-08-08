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
const int N = 2e6+5;
ll dp[N],inv[N];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=2000000;i++)
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
  ios_close;
  int t;
  cin>>t;
  int tot = 0;
  init();
  while(t--)
  {
    int n;
    cin>>n;
    cout<<"Case #"<<++tot<<":"<<endl;
    ll ans = dp[2*n]*quick(dp[n+1]*dp[n]%mod,mod-2)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
