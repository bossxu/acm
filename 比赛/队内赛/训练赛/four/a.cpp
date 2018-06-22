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
int n,k;
vector<int>map[50005];
int vis[50005];
ll dp[50005][502];
void dfs(int st)
{
  dp[st][0] = 1;
  vis[st] = 1;
  for(int i = 0;i<map[st].size();i++)
  {
    if(vis[map[st][i]])
      continue;

    dfs(map[st][i]);

    for(int j = 1;j<=k;j++)
    {
      dp[st][j]+=dp[map[st][i]][j-1];
    }

  }
}
void dfs_2(int st,int pre)
{
  vis[st] = 1;
  if(pre!=-1)
  {
    for(int i = k;i>=2;i--)
    {
      dp[st][i] += dp[pre][i-1]-dp[st][i-2];
    }
    dp[st][1]+=1;
  }
  for(int i = 0;i<map[st].size();i++)
  {
    if(!vis[map[st][i]])
    {
      dfs_2(map[st][i],st);
    }
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n>>k)
  {
    for(int i = 1;i<=n;i++) map[i].clear();
    for(int i = 1;i<=n-1;i++)
    {
      int a,b;
      cin>>a>>b;
      map[a].push_back(b);
      map[b].push_back(a);
    }
    clr(dp,0);
    clr(vis,0);
    dfs(1);
    clr(vis,0);
    dfs_2(1,-1);
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      //cout<<dp[i][k]<<endl;
      ans+=dp[i][k];
    }

    cout<<ans/2<<endl;
  }
  return 0;

}
