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

int n,m;
int p[1005];
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b >>=1;
  }
  return res;
}
int main()
{
  ios_close;
  ll inv = quick(100,mod-2);
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>p[i];
    }
    p[0] = 0;
    p[n+1] = 0;
    ll ans = 0;
    for(int i  = 1;i<=n;i++)
    {
      ll op = 1*(100-p[i-1])*inv;
      for(int j = i;j<=n;j++)
      {
        op = (op*p[j]%mod)*inv%mod;
        ans = (ans + (op*((100-p[j+1])*inv%mod)%mod)*quick(j-i+1,m))%mod;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
