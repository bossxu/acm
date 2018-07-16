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
const int mod = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
ll dp[105][105];
int shu[105];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    for(int i = 1;i<=n;i++)
    {
      dp[shu[i]][1] = 1;
      for(int j = 1;j<shu[i];j++)
      {
        for(int k = 1;k<i;k++)
        {
          if((double)(k+1)*log(j*1.0) < (double)(k)*log((double)shu[i]*1.0))
          {
            dp[shu[i]][k+1] = (dp[shu[i]][k+1]+dp[j][k]) % mod;
          }
        }
      }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=i;j++)
      {
        //cout<<i<<" "<<j<<" "<<dp[shu[i]][j]<<endl;
        ans = (ans+dp[shu[i]][j])%mod;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
