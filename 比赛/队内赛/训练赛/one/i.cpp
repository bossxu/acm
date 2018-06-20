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
int shu[200006];
int dp[200005];
int vis[200005];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
   int t;
   scanf("%d",&t);
   while(t--)
   {
     int n;
     scanf("%d",&n);
     clr(dp,INF);
     clr(vis,INF);
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&shu[i]);
     }
     dp[0] = 0;
     for(int i = 1;i<=n;i++)
     {
       dp[i] = min(dp[i-1],vis[shu[i]])+1;
       vis[shu[i]] = dp[i];
     }
     cout<<dp[n]-1<<endl;
   }
  return 0;
}
