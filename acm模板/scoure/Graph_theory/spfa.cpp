// Bellman Ford 存在最短路 这个比较难看感觉
//这个可以有负权
//但是  spfa 是在bellmen Ford 的基础上的加强
//这里用的是用前向星的方法去建图
//这里不用判重边的还是很舒服
int N,M;
int cnt;
struct edge{
int to,Next,w;
}E[maxn];
int pre[maxn],dp[maxn];//pre 路径结点 dp 最短路
bool vis[maxn];
int in[maxn];//这个的作用在于处理进去过多少次 就能看出是不是存在负环
void addedge(int x,int y,int z)
{
E[++cnt] .to = y;
E[cnt].Next = pre[x];
E[cnt].w = z;
pre[x] = cnt;
return;
}
bool spfa(int s)//这个算法还能判断是否存在负环
{
int i,t,temp;
queue<int>Q;
clr(vis,0);
clr(dp,INF);
clr(in,0);

Q.push(s);
vis[s] = true;
dp[s] = 0;

while(!Q.empty())
{
  t = Q.front();Q.pop();vis[t] = false;
  for(i = pre[t];i;i=E[i].Next)
  {
    temp = E[i].to;
    if(dp[temp] > dp[t]+E[i].w)
    {
      dp[temp] = dp[t]+E[i].w;
      if(!vis[temp])
      {
        Q.push(temp);
        vis[temp] = true;
        if(++in[temp]>N) return false; //负环判定关键
      }
    }
  }
}
return true;
}
