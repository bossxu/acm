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
struct node {
  /* data */
  int c,v;
};
vector<node>q[10005];
ll dp[10005];
ll ans;
int n;
ll dfs(int k)
{
  if(dp[k]!=0) return dp[k];
  for(int i=0;i<q[k].size();i++)
  {
    dp[k]=max(dfs(q[k][i].c)+q[k][i].v,dp[k]);
  }
  return dp[k];
}
int main()
{
  //freopen("/home/langman/桌面/in.txt","r",stdin);
  //freopen("/home/langman/桌面/out.txt","w",stdout);
  int t,m;
  cin>>t;
  while(t--)
  {
      cin>>n>>m;
      ans=0;
   for(int i=1;i<=n;i++)
     q[i].clear();
    for(int i=1;i<=m;i++)
    {
      node a;
      int b;
      scanf("%d%d%d",&b,&a.c,&a.v);
      q[b].push_back(a);
    }
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      ans= max(dfs(i),ans);
      //printf("---%lld\n",dp[i]);
    }
    printf("%lld\n",ans);
  }
  return 0;
}
