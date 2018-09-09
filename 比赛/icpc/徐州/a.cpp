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
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    b >>= 1;
    a = a*a%mod;
  }
  return res;
}
ll dp[1000005];
ll op[1000005];
int main()
{
  ios_close;
  int t;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    ll ok = quick(2,k);
    op[0] = 1;
    for(int i = 1;i<=100000;i++)
    {
      op[i] = op[i-1]*ok%mod;
    }
    op[0] = 0;
    dp[1] = 0;
    dp[2] = ok;
    dp[3] = (op[2]-dp[2])*2 -(op[1]-dp[1]) + dp[2]*ok;dp[3]%=mod;
    for(int i = 4;i<=n;i++)
    {
      dp[i] = (op[i-1]-dp[i-1])*2 -(op[i-2]-dp[i-2]) + (dp[i-1]*ok)%mod - (op[i-2]-dp[i-2] - op[i-3]+dp[i-3])*(ok-2)%mod;
      dp[i]%=mod;
    }
    ll ans = quick(ok,n);
    (ans -= dp[n])%=mod;
    ans += mod;
    cout<<ans%mod<<endl;
  }
  return 0;
}
