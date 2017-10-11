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
const int maxn =10005;
int tot;
int head[maxn];
int dp[maxn][3];
// dp[i][0] 他的子树下第一大
//dp[i][1] 他的子树下和dp[i][0] 不同结点第二大
//dp[i][2] 通过他父亲能走的最远的
//前向星建图发
// 这是真的难
// 要理解下前向星,当然最重要的其实在于dp公式的推到
// 树形dp可能很多都要用到这样的一种思想,开多维,记录不同的状态
// 很好的一道题
// 前向星的目的在于就是巴一个你不知道结构的树,搞成一个有根结点的树

struct EDGE{
  int v;//儿子
  int next;//同父的下一个结点
  int w;//权
}edge[maxn*2];
void addedge(int u,int v,int w)
{
  edge[tot].v=v;
  edge[tot].w=w;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void dfs1(int u,int v)
{
  for(int i=head[u];i!=-1;i = edge[i].next)
  {
    int v = edge[i].v;
    dfs1(v,u);
    int w = edge[i].w;
    int temp = dp[v][0]+w;
    if(temp >= dp[u][0])
    {
      dp[u][1]=dp[u][0];
      dp[u][0]=temp;
    }
    else
    {
      dp[u][1] =max(dp[u][1],temp);
    }
  }
}
void dfs2(int u,int v)
{
  for(int i = head[u];i!=-1;i=edge[i].next)
  {
    int v =edge [i].v;
    if(dp[v][0]+edge[i].w == dp[u][0])
    {
      dp[v][2] = max( dp[u][2],dp[u][1]) + edge[i].w;
    }
    else
    {
      dp[v][2] = max(dp[u][0],dp[u][2]) + edge[i].w;
    }
    dfs2(v,u);
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  while(cin>>n)
  {
      tot = 1;
      clr(dp,0);
      clr(head,-1);
      for(int i=2;i<=n;i++)
      {
        int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,i,b);
      }
      dfs1(1,-1);
      dfs2(1,-1);
      for(int i=1;i<=n;i++)
        cout<<max(dp[i][0],dp[i][2])<<endl;

  }

  return 0;
}
