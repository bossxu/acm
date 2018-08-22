#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const double eps = 1e-6;
ll mod;
ll dp[8000];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=7000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}
ll mod_inverse(ll a, ll m)
{
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
ll A(int n,int m)
{
  if(m>n) return 0;
  return dp[n]*mod_inverse(dp[n-m],mod-2)%mod;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m>>mod;
    init();
    ll ans = dp[n*m];
    ll op = 0;
    for(int i = n+m-1;i<n*m;i++)
    {
      op = op+A(i-1,n+m-2)*n%mod*m%mod+dp[n*m-n-m+1];
    }
    (ans -= op)%=mod;
    ans = (ans+mod)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
