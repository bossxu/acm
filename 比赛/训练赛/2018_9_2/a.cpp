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
ll gcd(ll a,ll b)
{
  return b == 0?a:gcd(b,a%b);
}
int main()
{
  ios_close;
  ll n,k;
  while(cin>>n>>k)
  {
    ll ans = k*(n/gcd(n,k)-1)*gcd(n,k) + (k-1)*(gcd(n,k)-1);
    cout<<ans<<endl;
  }
  return 0;
}
