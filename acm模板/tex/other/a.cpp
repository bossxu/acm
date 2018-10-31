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
  return i*m+j;
}
int vis[20][20];
int Hash[20][20];
bool check(int i,int j)
{
  if(i<0 || j <0 || i>=n || j>=m || shu[i][j] == '#') return false;
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
int flag = 0;
void dfs(int x,int y) // 判可行
{
  if(shu[x][y] == '$') tag = 1;
  if(Hash[x][y] == -1) Hash[x][y] = flag++;
  vis[x][y] = 1;
  for(int dx = -1;dx<=1;dx++)
  {
    for(int dy = -1;dy <= 1;dy++)
    {
      if(dx == dy || dx+dy == 0) continue;
      if(check(x+dx,y+dy) && vis[x+dx][y+dy]==0)

          dfs(x+dx,y+dy);
    }
  }
}
void build()
{
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<m;j++)
    {
      if(Hash[i][j] == -1)
      {
        continue;
      }
      if(shu[i][j] == '$')
      {
        op[Hash[i][j]][Hash[i][j]] = 1;
        dp[Hash[i][j]] = 0;
        continue;
      }
      else
      {
        if(check(i+1,j)) op[Hash[i][j]][Hash[i+1][j]] = -1.0;
          if(check(i-1,j)) op[Hash[i][j]][Hash[i-1][j]] = -1;
            if(check(i,j+1)) op[Hash[i][j]][Hash[i][j+1]] = -1;
              if(check(i,j-1)) op[Hash[i][j]][Hash[i][j-1]] = -1;
        op[Hash[i][j]][Hash[i][j]] = num(i,j);
        dp[Hash[i][j]] = num(i,j);
      }
    }
  }
}
int var,equ;
int Gauss()//Gauss消元求解
{
    var = equ = flag;
    for(int k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        int max_r = k;
        for(int i = k + 1; i < equ; i++)
            if(fabs(op[i][col]) > fabs(op[max_r][col]))
                max_r = i;
        if(fabs(op[max_r][col]) < eps) return 0;
        if(k != max_r)
        {
            for(int j = col; j < var; j++)
                swap(op[k][j], op[max_r][j]);
            swap(dp[k], dp[max_r]);
        }
        dp[k] /= op[k][col];
        for(int j = col + 1; j < var; j++) op[k][j] /= op[k][col];
        op[k][col] = 1;
        for(int i = 0; i < equ; i++)
            if(i != k)
            {
                dp[i] -= dp[k]*op[i][col];
                for(int j = col + 1; j < var; j++) op[i][j] -= op[k][j]*op[i][col];
                op[i][col] = 0;
            }
    }
    return 1;
}
int main()
{
//  ios_close;
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(scanf("%d%d",&n,&m) == 2)
  {
    flag = 0;
    clr(dp,0);
    clr(op,0);
    clr(vis,0);
    clr(Hash,-1);
    int a,b;
    int x,y;
    tag = 0;
    for(int i = 0;i<n;i++)
    {
        scanf("%s",shu[i]);
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
          if(shu[i][j] == '@') x = i,y = j,b = cal(i,j);
        }
    }
    dfs(x,y);
    build();
    // cout<<flag<<endl;
    // for(int i = 0;i<flag;i++)
    // {
    //   for(int j = 0;j<flag;j++)
    //   {
    //     cout<<op[i][j]<<" ";
    //   }
    //   cout<<dp[i]<<endl;
    // }
    if(tag == 0)
    {
      printf("-1\n");
      continue;
    }
    Gauss();
    printf("%.6lf\n",dp[Hash[x][y]]);
  }
  return 0;
}
