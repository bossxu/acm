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
#define mod 1e9+7
const int maxn = 205;
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
int likef[105][105],liked[105][105];
int st,en;
// 知识点分解： 最大流
struct edge{//to 终点 cap 流量 rev 反向边
    int to,cap,rev;
};
vector<edge> map[4*maxn];       
int iter[4*maxn],level[4*maxn]; //在利用dfs求最短路的时候用的上。
void add_edge(int f,int t,int c)
{
    edge a,b;
    a.to = t,a.cap=c,a.rev=map[t].size();
    b.to = f,b.cap=0,b.rev=map[f].size()-1;
    map[f].push_back(a);// 正常路
    map[t].push_back(b) ;// 增广路
}
int dfs(int v,int t,int f)
{
    if(v==t)
    return f;
    for(int &i=iter[v];i<map[v].size();i++)
    {
        edge &e=map[v][i];
        if(  e.cap>0 && level[v]<level[e.to])
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                map[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
void bfs(int s)
{
  clr(level,-1);
  queue<int>q;
  level[s]=0;
  q.push(s);
  while(!q.empty())
  {
      int v=q.front();
      q.pop();
      for(int i=0;i<map[v].size();i++)
  {
      edge &e=map[v][i];
      if(e.cap>0 && level[e.to]<0)
      {
          level[e.to]=level[v]+1;
          q.push(e.to);
      }
  }
  }
}
int max_flow(int s ,int t)
{
    int flow =0;
   while(1)
   {
       bfs(s);
       if(level[t]<0) return flow;
       clr(iter,0);
       int f;
       while(f=dfs(s,t,INF)>0) flow+=f;
   }
}
void init(int n,int f,int d)
{
  //用来预处理，建边
  // <1,f>     <f+1,f+n>   <f+n+1, f+2n> <f+2n+1,f+2n+d>
  //先设置一个源点，和一个终点
  st = 2*n+f+d+1,en=st+1;
  for(int i = 1;i<=en;i++)
  {
      map[i].clear();
  }
  for(int i=1;i<=f;i++)//源点到食物
  {
      add_edge(st,i,1);
  }
  for(int i=1;i<=n;i++)//牛到牛
  {
      add_edge(f+i,f+n+i,1);
  }
  for(int i=1;i<=d;i++)//饮料到终点
  {
      add_edge(2*n+f+i,en,1);
  }
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=f;j++)
        if(likef[i][j])
        {
            add_edge(j,f+i,1);
        }
      for(int j=1;j<=d;j++)
        if(liked[i][j])
        {
            add_edge(f+n+i,f+2*n+j,1);
        }  
  }
}
int main()
{
    int  n,f,d;
    while(cin>>n>>f>>d)
    {
        clr(likef,0);
        clr(liked,0);
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            while(a--)
            {
                int z;
                cin>>z;
                likef[i][z]=1;
            }
            while(b--)
            {
                int z;
                cin>>z;
                liked[i][z]=1;
            }
        }
        init(n,f,d);
        printf("%d\n",max_flow(st,en));
    }
    return 0;
}