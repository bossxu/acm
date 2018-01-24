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
//dijkstra 算法
int map[2005][2005];//记录路径 注意双向
int dp[2005];//单源最短路径记录
bool vis[2005];//记录是否用过
int N;//顶点数
void dijkstra(int s)
{
  clr(dp,INF);
  clr(vis,0);
  dp[s] = 0;
  while(true)
  {
    int v = -1;
    for(int u = 1;u<=N;u++)//从没用过的点中找一个距离最小的顶点
    {
      if(!vis[u] && (v==-1 || dp[u]<dp[v]) )
      v = u;
    }
    if(v == -1) break;
    vis[v] = true;
    for(int i = 1;i<=N;i++)
    {
      dp[i] = min(dp[i],dp[v]+map[v][i]);
    }
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n,m;
   while(cin>>m>>n)
   {
     if(!n && !m) break;
     N = n;
     clr(map,INF);
     for(int i = 1;i<=m;i++)
     {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        map[a][b] = min(c,map[a][b]);
        map[b][a] = map[a][b];
     }
     dijkstra(1);
     cout<<dp[n]<<endl;
   }
  return 0;
}
