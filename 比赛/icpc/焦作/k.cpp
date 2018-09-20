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
ll dp[2][10005];
vector<ll>csl;
int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
    csl.clear();
    int n,q; scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;i++)
    {
      ll v,c;
      scanf("%lld%lld",&v,&c);
      for(int i = 0;i<c;i++)
      {
        ll ans = v*(1<<i);
        if(ans > 10000) break;
        csl.pb(ans);
      }
    }
    clr(dp,0);
    dp[0][0] = 1;
    int len = csl.size();
    int now = 0;
    int ne;
    for(int i = 0;i<len;i++)
    {
      ne = now^1;
      for(int s = 0;s<=10000;s++)
      {
        dp[ne][s] = dp[now][s];
        if(s >= csl[i]) dp[ne][s] += dp[now][s-csl[i]];
        dp[ne][s]%=mod;
      }
      now^=1
    }
  for(int i = 1;i<=q;i++)
  {
    int p;
    scanf("%d",&p);
    printf("%lld\n",dp[now][p]%mod);
  }
  }
  return 0;
}
