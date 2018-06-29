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
int map[505][505];
int vis[505][505];
int dp[505][505];
int n,m;
int dfs(int x,int y)
{
    if(vis[x][y]) return dp[x][y];
    vis[x][y] = 1;
    int flag = (x+y)%2;
    if(x>n || y>m)
    {
      if(flag)
      {
        return INF;
      }
      else
      {
        return -INF;
      }
    }
    ll ans;
    if(!flag)
    {
      dp[x][y] =  map[x][y]+min(dfs(x+1,y),dfs(x,y+1));
    }
    else
    {
      dp[x][y] = -map[x][y]+max(dfs(x+1,y),dfs(x,y+1));
    }
    return dp[x][y];
}
int main()
{
    int t;
    cin>>t;
    std::ios::sync_with_stdio(false);
    //freopen("in.txt","w")
    while(t--)
    {
        clr(map,0);
        clr(vis,0);
        clr(dp,0);
        cin>>n>>m;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                cin>>map[i][j];
            }
        }
        vis[n][m] = 1;
        dp[n][m] = (n+m)%2 == 0?map[n][m]:-map[n][m];
        cout<<dfs(1,1)<<endl;

    }
}
