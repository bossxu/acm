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
const double eps = 1e-6;
int dp[6004][2];
vector<int>pre[6004];
int ans = 0;
int father[6004];
// cin 500ms scanf 100ms
// 神奇
void dfs(int n)
{
  for(int i=0;i<(int)pre[n].size();i++)
  {
    dfs(pre[n][i]);
    dp[n][0] += max(dp[pre[n][i]][1],dp[pre[n][i]][0]);
    dp[n][1] += dp[pre[n][i]][0];
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   while(cin>>n)
   {
      clr(dp,0);
      clr(father,0);
      for(int i = 1;i<=n;i++)
      {
        pre[i].clear();
        scanf("%d",&dp[i][1]);
      }
      int a,b;
      while(scanf("%d%d",&a,&b) && a && b)
      {
        pre[b].push_back(a);
        father[a] = b;
      }
      int k = 1;
      while(father[k]!=0)
       k = father[k];
      dfs(k);
      cout<<max(dp[k][0],dp[k][1])<<endl;
   }
  return 0;
}
