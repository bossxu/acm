//prime 算法
//还有一个不想去写了 没有这个必要
//注意重边
// 还有这个算法 在树生成不起来的情况下 需要特判一下
// dfs一遍就行 看是否全联通
int map[maxn][maxn];
int dp[maxn];
int vis[maxn];
int N;
int prime()
{
  clr(dp,INF);
  clr(vis,0);
  dp[1] = 0;
  int res = 0;
  while(true)
  {
    int v = -1;
    for(int u = 1;u<=N;u++)
    {
      if(!vis[u] && (v==-1 || dp[u]<dp[v])) v = u;
    }
    if(v == -1) break;
    vis[v] = 1;
    res += dp[v];
    for(int u = 1;u<=N;u++)
    {
      dp[u] = min(dp[u],map[v][u]);
    }
  }
  return res;
}
