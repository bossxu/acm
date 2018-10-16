//langman
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
char shu[20][20];
double dp[230]; // 这个表示的是现在这个点到终点的期望
double op[230][230];
int n,m;
int cal(int i,int j)  //算出一维坐标
{
  return (i-1)*m+j;
}
bool check(int i,int j)
{
  if(i<1 || j <1 || i>n || j>m || shu[i][j] == '#') return false;
  return true;
}
int num(int i,int j)
{
  int tot = 0;
  if(check(i+1,j)) tot++;
  if(check(i,j+1)) tot++;
  if(check(i-1,j)) tot++;
  if(check(i,j-1)) tot++;
  return tot;
}
bool tag;
int vis[20][20];
void dfs(int x,int y)
{
  if(shu[x][y] == '$') tag = 1;
  vis[x][y] = 1;
  for(int dx = -1;dx<=1;dx++)
  {
    for(int dy = -1;dy <= 1;dy++)
    {
      if(dx == dy || dx+dy == 0) continue;
      if(check(x+dx,y+dy) && !vis[x+dx][y+dy])
          dfs(x+dx,y+dy);
    }
  }

}
int main()
{
//  ios_close;
  while(scanf("%d%d",&n,&m) == 2)
  {
    clr(dp,0);
    clr(op,0);
    clr(vis,0);
    int a,b;
    int x,y;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        scanf("%c",&shu[i][j]);
        if(shu[i][j] == '$') b = cal(i,j);
        if(shu[i][j] == '@') a = cal(i,j),x = i,y = j;
      }
    }
    dfs(x,y);
    if(tag == 0)
    {
      printf("-1\n");
      continue;
    }
    op[b][b] = 1;
    dp[b] = 0;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        int tot = num(i,j);
        if(shu[i][j] == '$') continue;
        if(tot == 0)
        {  dp[cal(i,j)] = INF;  continue; }
        op[cal(i,j)][cal(i,j)] = 1;
        if(check(i+1,j)) op[cal(i,j)][cal(i+1,j)] = -1.0/tot;
        if(check(i,j+1)) op[cal(i,j)][cal(i,j+1)] = -1.0/tot;
        if(check(i-1,j)) op[cal(i,j)][cal(i-1,j)] = -1.0/tot;
        if(check(i,j-1)) op[cal(i,j)][cal(i,j-1)] = -1.0/tot;
      }
    }

  }
  return 0;
}
