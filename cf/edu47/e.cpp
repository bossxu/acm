#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int mod = 998244353;
#define clr(a,x) memset(a,x,sizeof(a))
ll dp[1000006];
ll quick(ll a, ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b/=2;
  }
  return res;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
     ll ans = 0;
     for(int i = 1;i<=n;i++)
     {
       cin>>dp[i];
     }
     for(int i = 1;i<=n-1;i++)
     {
       ans = (ans+(dp[i]*(n-i+2)%mod)*quick(2,n-i-1)%mod)%mod;
     }
     ans = (ans+dp[n]) %mod;
     cout<<ans<<endl;
  }
  return 0;
}
