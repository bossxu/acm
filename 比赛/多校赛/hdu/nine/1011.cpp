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
  while(t--)
  {
      ll a,b,c,d;
      cin>>a>>b>>c>>d;
      ll ans = 0;
      ans += quick(2LL,a);
      ans += quick(2LL,a)*(quick(2LL,b)-1)%mod;
      ans += quick(2LL,a)*(quick(2LL,c)-1)%mod;
      ans += d*quick(2LL,a+c)%mod + b*quick(2LL,a)%mod*(quick(2LL,c)-1)%mod;
      ans = (ans%mod+mod)%mod;
      cout<<ans<<endl;
  }
  return 0;
}
