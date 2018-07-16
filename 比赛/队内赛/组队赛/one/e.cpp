#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll quick(ll a, ll n)
{
  ll res = 1;
  while(n)
  {
    if(n&1) res = res*a%mod;
    a = a*a%mod;
    n>>=1;
  }
  return res;
}
ll shu[100005];
ll dp[100005];
void init()
{
  for(int i = 1;i<=100000;i++)
  {
    dp[i] = quick(i,mod-2);
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  int t;
  scanf("%d",&t);
  init();
  while(t--)
  {
    int n;
    scanf("%d",&n);
    ll op = 1;
    for(int i = 1;i<=n;i++)
    {
      scanf("%lld",&shu[i]);
      op = op*shu[i]%mod;
    }
    ll sum  = 0;
    for(int i = 1;i<=n;i++)
    {
      if(shu[i] == 1) continue;
      sum = sum + (shu[i]-1)*(op*dp[shu[i]]%mod)%mod;
      //cout<<sum<<endl;
    }
    printf("%lld\n",sum%mod);
  }
  return 0;
}
