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
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int shu[100005];
ll dp[100005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    shu[0] = 0;
    clr(dp,0);
    shu[n+1] = m;
    for(int i = 1;i<=n+1;i+=2)
    {
      ans+=shu[i]-shu[i-1];
    }
    for(int i = n;i>=1;i--)
    {
      int flag = (i%2 == 0?1:-1);
      dp[i] = dp[i+1]+flag*(shu[i+1]-shu[i]);
    }
    // for(int i = 1;i<=n;i++)
    // {
    //   cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    ll light = 0;
    for(int i = 1;i<=n;i++)
    {
      if(i%2 == 1) light+=shu[i]-shu[i-1];
      ll maxn = 0;
      if(i%2)
      {
        if(shu[i+1]!=shu[i]+1)
        {
          maxn = light + (m-dp[i]-1-shu[i])/2;
          ans = max(ans,maxn);
        }
      }
      else
      {
        if(shu[i-1]!=shu[i]-1)
        {
          maxn = light + (m-shu[i]+dp[i])/2;
          ans = max(ans,maxn);
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
