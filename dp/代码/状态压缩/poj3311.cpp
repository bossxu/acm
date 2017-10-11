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
int map[13][13];
int dp[1<<12][12];
int n;
int dis[13][13];
void floyd()
{
  for(int i=0;i<=n;i++)
   for(int j = 0;j<=n;j++)
    for(int z = 0;z<=n;z++)
      dis[i][j] = min(dis[i][j],dis[i][z]+map[z][j]);
}
//我觉得这题还是有点难，他的方向是不确定的压缩的东西很奇怪，很神奇
//想不到，他把现在的状态，就是走过的所有店看作压缩
//学习，真的很难想到，这和之前的不太一样;
int main()
{
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    while(cin>>n && n)
    {
      for(int i =0;i<=n;i++)
       for(int j = 0;j<=n;j++)
         {
           cin>>map[i][j];
           dis[i][j] = map[i][j];
         }
      floyd();
      clr(dp,-1);
      dp[1][0] = 0;
      for(int i =1;i < 1<<(n+1);i++)
      {
        i =i|1;
        for(int j = 0;j<=n;j++)
        {
          if(dp[i][j] != -1)
          {
            for(int k=0;k<=n;k++)
            {
              if(j!=k && (dp[(1<<k)|i][k]==-1 || dp[(1<<k)|i][k]>dp[i][j]+dis[j][k]))
                 dp[(1<<k)|i][k]=dp[i][j]+dis[j][k];
            }
          }
        }
      }
      cout<<dp[(1<<(n+1))-1][0]<<endl;
    }
    return 0;
}
