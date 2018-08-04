#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
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
  ll n,m;
  while(cin>>n>>m)
  {
    cout<<n*quick(m,mod-2)%mod<<endl;
  }
  return 0;
}
