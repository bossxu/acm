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
//最大流 dinic算法
const int MAXN = 1000;
struct edge{ll to,cap,rev;};
vector<edge>G[MAXN];
int level[MAXN];
int iter[MAXN];
void addedge(ll from,ll to,ll cap)
{
  G[from].push_back((edge){to,cap,(ll)G[to].size()});
  G[to].push_back((edge){from,0,(ll)G[from].size()-1});
}
void bfs(int s)
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
int dfs(int v, int t,int f)
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
int max_flow(int s,int t)
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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  int flag = 0;
  int n,m;
  while(cin>>m>>n)
  {
    ll a,b;
    ll c;
    for(int i = 1;i<=n;i++) G[i].clear();
    for(int i = 1;i<=m;i++)
    {
      cin>>a>>b>>c;
      addedge(a,b,c);
    }
    //printf("Case %d: ",++flag);
    cout<<max_flow(1,n)<<endl;
  }
  return 0;
}
