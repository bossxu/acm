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
int n;
const int maxn=20005;
const double eps = 1e-6;
struct st{
  int t1,t2;
  // int next;
}node[105];
int ans;
int vis[105];
void dfs(int i,int now)
{
  if(i>n)
  {
    if(now>ans)
     ans=now;
     return ;
  }
  if(vis[i])
    dfs(i+1,now+node[i].t1);
  else
  {
    if(node[i].next > i)
    {
      vis[i]=1;
      dfs(i+1,now+node[i].t1);
      vis[i]=0;
    }
    vis[i]=1;
    dfs(node[i].next,now+node[i].t2);
    vis[i]=0;
  }

}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     cin>>n;
     ans=0;
     for(int i=1;i<=n;i++)
     {
       scanf("%d%d%d",&node[i].t1,&node[i].t2,&node[i].next);
     }
     clr(vis,0);
     dfs(1,0);
     cout<<ans<<endl;
   }

  return 0;
}
