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
const int maxn = 50005;
int head[maxn],tot;
int vis[maxn];
int n,num;
int dp[maxn];//这里记录的是当前结点所有子树的规模大小
int ans[maxn];
int maxsize;
struct Edge{
  int to,next;
}edge[2*maxn];
//树的重心
// 188ms的做法
//边是1,所以这里的前向星其实不需要太多的操作,边的长度不需要处理
void addedge(int to , int v)
{
   edge[tot].to = v ;
   edge[tot].next = head[to] ;
   head[to] = tot ++ ;
}
void dfs(int u)
{
  vis[u] = 1;
  dp[u] = 0;
  int sonmax = 0;
  for(int i = head[u];i!=-1;i = edge[i].next)
  {
    int v = edge[i].to;
    if(!vis[v])
  {
    dfs(v);
    dp[u]+=dp[v]+1;
    sonmax = max(sonmax , dp[v]+1);
  }
  }
  sonmax = max (sonmax , n - dp[u] -1);
  if(sonmax<maxsize)
  {
    ans[0] = u;
    num = 1;
    maxsize = sonmax;
  }
  else if(sonmax == maxsize)
  {
    ans[num] = u;
    num++;
  }
}
inline int read()// 可能这就是开挂b吧
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
     clr(dp,0);
     maxsize = INF;
     clr(vis,0);
     clr(head,-1);
     tot = 1;
     for(int i=1;i<n;i++)
     {
       int a,b;
       a = read(),b=read();
       addedge(a,b);
       addedge(b,a);
     }
     dfs(1);

     sort(ans,ans+num);
     for(int i=0;i<=num-1;i++)
     {
       printf("%d\n",ans[i]);
     }
   }
  return 0;
}
