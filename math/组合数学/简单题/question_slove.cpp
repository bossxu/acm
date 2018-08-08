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
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
int main()
{
  ll n,m;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    ll ans = (quick(m,n+1)-1)*quick(m-1,mod-2)%mod;
    ans = (ans+mod)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
