// langman
#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
// 期望入门题
// 网上说 概率dp一般是正着推 期望dp一般是倒过来退。
// 好像有点道理
// dp[i] 表式的是从i这个点 到第n个点所要用的期望。
double dp[100010];
int vis[100010];
int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m) == 2)
  {
    if(!m && !n) break;
    for(int i = 0;i<=n+6;i++)
    {
      dp[i] = 0;
      vis[i] = -1;
    }
    for(int i = 1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      vis[u] = v;
    }
    for(int i = n-1;i>=0;i--)
    {
      if(vis[i] != -1)
      {
        dp[i] = dp[vis[i]];
      }
      else
      {
        for(int j = 1;j<=6;j++)
        {
          dp[i] += dp[i+j]/6.0;
        }
        dp[i]+=1;
      }
    }
    printf("%.4lf\n",dp[0]);
  }
  return 0;
}
