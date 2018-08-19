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
   if(m>n) return 0;
   if(m == n) return 1;
   ll ans = (dp[n]*inv[m]%mod)*inv[n-m]%mod;
   return ans;
}
int main()
{
  int t;
  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  cin>>t;
  init();
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
      ans = (ans+flag*C(m,i)*C(down,up)%mod)%mod;
      down-=n;
      if(down<up) break;
      flag *= -1;
    }
    cout<<(ans+mod)%mod<<endl;
  }
  return 0;
}
