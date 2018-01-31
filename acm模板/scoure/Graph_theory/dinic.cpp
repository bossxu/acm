//最大流 dinic算法
//记得有时候要建双向边
const int MAXN = 1000;
struct edge{int to,cap,rev;};   //用边来存图
vector<edge>G[MAXN];            //图的链接表表示
int level[MAXN];                //顶点到源点的距离标号
int iter[MAXN];                 //当前弧在其之前的边已经没有用了

void addedge(int from,int to,int cap)    //为图加一条从from到to的容量为cap的边
{
  G[from].push_back((edge){to,cap,(int)G[to].size()});
  G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(int s)              //bfs计算从源点出发的距离标号
{
  clr(level,-1);
  queue<int>que;
  level[s] = 0;
  que.push(s);
  while(!que.empty())
  {
    int v = que.front();
    que.pop();
    for(int i = 0;i<G[v].size();i++)
    {
      edge &e = G[v][i];
      if(e.cap>0 && level[e.to]<0)
      {
        level[e.to] = level[v]+1;
        que.push(e.to);
      }
    }
  }
}
int dfs(int v, int t,int f)             //通过dfs寻找增广路
{
  if(v == t) return f;
  for(int i = iter[v] ;i<G[v].size();i++)
  {
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to])
    {
       int d = dfs(e.to,t,min(f,e.cap));
       if(d>0)
       {
          e.cap -=d;
          G[e.to][e.rev].cap += d;
          return d;
       }
    }
  }
  return 0;
}
int max_flow(int s,int t)    //从 s 到 t 的最大流
{
  int flow = 0;
  while(true)
  {
    bfs(s);
    if(level[t] < 0 ) return flow;
    clr(iter,0);
    int f;
    while((f = dfs(s,t,INF)) > 0 )
    flow += f;
  }
}
