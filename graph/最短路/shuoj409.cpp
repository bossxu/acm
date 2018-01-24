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
const int maxn = 20005;
  // Bellman Ford 存在最短路 这个比较难看感觉
  //这个可以有负权
  //但是  spfa 是在bellmen Ford 的基础上的加强
  //这里用的是用前向星的方法去建图
int N,M;
int cnt;
struct edge{
  int to,Next,w;
}E[maxn];
int pre[maxn],dp[maxn];//pre 路径结点 dp 最短路
bool vis[maxn];
int in[maxn];
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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>N>>M)
  {
    if(!N && !M) break;
    int a,b,cost;
    cnt = 0;
    clr(pre,0);
    for(int i = 1;i<=M;i++)
    {
      scanf("%d%d%d",&a,&b,&cost);
      addedge(a,b,cost);
      //addedge(b,a,cost);
    }
    if(spfa(1))  cout<<dp[N]<<endl;
    else
    cout<<"No"<<endl;
  }
  return 0;
}
