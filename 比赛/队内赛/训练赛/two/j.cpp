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
vector<int>q[6005];
int shu[6005];
int dp[6005][2];
int vis[6005];
void dfs(int root)
{
  vis[root] = 1;
  dp[root][1] = shu[root];
  for(int i = 0;i<q[root].size();i++)
  {
    if(!vis[q[root][i]])
    {
      dfs(q[root][i]);
      dp[root][1] += dp[q[root][i]][0];
      dp[root][0] += max(dp[q[root][i]][1],dp[q[root][i]][0]);
    }
  }

}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
     clr(dp,0);
     for(int i = 1;i<=n;i++)
     {
       q[i].clear();
       cin>>shu[i];
     }
     int a,b;
     while(true)
     {
       cin>>a>>b;
       if(!a && !b) break;
       q[a].push_back(b);
       q[b].push_back(a);
     }
     clr(vis,0);
     dfs(1);

     cout<<max(dp[1][0],dp[1][1])<<endl;
   }
  return 0;
}
