#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int mod,n,m;
const double eps = 1e-6;
const int MAXN = 1000005;
ll phi[MAXN];
ll inv[MAXN];
ll dp[MAXN];
int maxn = MAXN;
void init()
{
  for(int i = 1;i<=maxn;i++) phi[i] = i;
  for(int i = 2;i<=maxn;i+=2) phi[i]/=2;
  for(int i = 3;i<=maxn;i+=2)
  {
    if(phi[i] == i)
    {
      for(int j = i;j<=maxn;j+=i)
      {
        phi[j] = phi[j]/i*(i-1);
      }
    }
  }
}
void dell()
{
  inv[1]=1;
  for(int i=2;i<=n;i++)
      inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  for(int i = 1;i<=n;i++)
  {
    dp[i] = inv[i]*phi[i]%mod;
  }
}
ll csl[MAXN];
int main()
{
  ios_close;
  init();
  int t;
  cin>>t;
  while(t--)
  {
    clr(csl,0);
    cin>>n>>m>>mod;
    if(n>m) swap(n,m);
    dell();
    ll ans = 0;
    for(int i = n;i>=1;i--)
    {
      csl[i] = (m/i)*(n/i);
      for(int j = i+i;j<=n;j+=i)
      {
        csl[i]-=csl[j];
      }
      ans = (ans+(csl[i]%mod)*dp[i]%mod)%mod;
    }
    cout<<ans%mod<<endl;
  }
  return 0;
}
