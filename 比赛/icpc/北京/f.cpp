#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll mod;
const double eps = 1e-6;
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(a&1) res = res*a%mod;
    a + a*a%mod;
    b>>=1;
  }
  return res;
}

int main()
{
  ios_close;
  int t;cin>>t;
  cin>>mod;
  while(t--)
  {
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    ll bian = n*(n-1)/2;
    ll op = quick(3*1LL,bian-1);
    ans = bian*op%mod*(quick(2LL,k)+1)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
