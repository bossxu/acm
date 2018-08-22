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
ll fac[8000];
void init()
{
  fac[0] = 1;
  for(int i = 1;i<=7000;i++)
  {
    fac[i] = fac[i-1]*i%mod;
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
  return fac[n]*mod_inverse(fac[n-m],mod)%mod;
}
int main()
{
  int n,m;
  while(cin>>n>>m>>mod)
  {
    init();
    cout<<A(n,m)<<endl;
  }
  return 0;
}
