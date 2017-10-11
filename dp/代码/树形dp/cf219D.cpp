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
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
const int maxn = 2*1e5+5;
struct Edge
{
  int next,to,w;
}edge[2*maxn];
int tot,head[maxn];
int num[maxn],dp[maxn];
// num 子树结点数
// dp  走完子树所要花费的路程
void add(int u, int v,int w)
{
  edge[tot].to=v;
  edge[tot].w=w;
  edge[tot].next = head[u];
  head[u] = tot++;
}
bool vis[maxn];
int n;
int mmin;
int nnum;
int ans[maxn];
void dfs_1(int u, int v)
{
  vis[u] = 1;
  num[u] = 1;
  dp[u] = 0;
  for(int i = head[u];i!=-1;i = edge[i].next)
  {
    int v = edge[i].to;
    int w = edge[i].w;
    if(!vis[v])
    {
     dfs_1(v,u);
     num[u]+=num[v];
     dp[u]+=dp[v]+w;
    }
  }
  printf("num[u]==%d  dp[u]==%d\n",num[u],dp[u]);
}
void dfs_2(int u,int v)
{
  vis[u]=1;
  for(int i = head[u];i!=-1;i = edge[i].next)
  {
    int v = edge[i].to;
    if(vis[v])
    continue;
    dp[v] += n-num[v]-(dp[u]-dp[v]);
    printf("U==%d  V==%d  dp[u]==%d\n",u,v,dp[u]);
    if(dp[v]<mmin)
    {
      ans[0] = u;
      nnum=1;
      mmin = dp[v];
    }
    else if(dp[v]==mmin)
    {
      ans[nnum++]=v;
    }
    dfs_2(v,u);
  }
}
inline int read()// 可能这就是开挂吧
{
    char k=0;char ls;ls=getchar();for(;ls<'0'||ls>'9';k=ls,ls=getchar());
    int x=0;for(;ls>='0'&&ls<='9';ls=getchar())x=x*10+ls-'0';
    if(k=='-')x=0-x;return x;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  while(cin>>n)
  {
    clr(head,-1);
    for(int i = 1; i<n ;i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      add(a,b,0);
      add(b,a,1);
    }
    tot = 1;
    clr(vis,0);
    dfs_1(1,-1);
    mmin = INF;
    clr(vis,0);
    dfs_2(1,-1);
    cout<<mmin<<endl;
    for(int i = 0;i<nnum-1;i++)
    printf("%d ",dp[ans[i]]);
    cout<<dp[ans[nnum-1]]<<endl;
  }

  return 0;
}
