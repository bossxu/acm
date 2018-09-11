#include <bits/stdc++.h>
using namespace std;

#define clr(shu, x) memset(shu, x, sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
const int mod = 1e9 + 7;
const double eps = 1e-6;
ll inv = (mod+1)/2;
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = a*res%mod;
    b>>=1;
    a = a*a%mod;
  }
  return res;
}
ll cal_1(ll n)
{
  return n*(n+1)%mod*inv%mod;
}
ll cal_f(ll n)
{
  return n*(n+1)%mod*(2*n+1)%mod*quick(6*1LL,mod-2)%mod;
}
ll a[10005];
void init()
{
  a[0] = 0;
  a[1] = 2;
  for(int i = 2;i<=10000;i++)
  {
    a[i] = (i+1)*i%mod;
  }
}
int gcd(int a,int b){return b == 0?a:gcd(b,a%b);}
int main() {

    int n,m;
    init();
    while(cin>>n>>m)
    {
      ll ans = 0;
      for(int i = 1;i<=n;i++)
      {
        if(gcd(i,m) == 1)
        {
          ans += a[i];
        }
      }
      cout<<ans<<endl;
    }
  return 0;
}
