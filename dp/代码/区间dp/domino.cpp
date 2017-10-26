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
int dp[105][105];
int p[105],h[105];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)
    cin>>p[i]>>h[i];
    int i,j;
    clr(dp,INF);
    for( i = 1;i<=n;i++)
    {
      int dis = p[i]+h[i];
      dp[i][i] = 1;
      for( j = i+1;j<=n;j++)
      {
        if(dis<=p[j])
        break;
        dis = max(dis,p[j]+h[j]);
      }
      dp[i][j-1] = 1;
    }
    for(i = n;i>0;i--)
    {
      int dis = p[i]-h[i];
      for( j=i-1;j>0;j--)
      {
        if(dis>=p[j])
        break;
         dis = min(dis,p[j]-h[j]);
      }
      dp[j+1][i] = 1;
    }
    for(int k = 1;k <= n;k++)
    {
      for(int i = 1;i<=k;i++)
      {
        for(int j = k+1;j<=n;j++)
        {
          if(dp[i][k]!=INF && dp[k+1][j]!=INF)
            dp[i][j] = min(dp[i][k]+dp[k+1][j],dp[i][j]);
        }
      }
    }
    /*for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=n;j++)
        cout<<dp[i][j]<<"--";
        cout<<endl;
      }*/
    cout<<dp[1][n]<<endl;
  }
  return 0;
}
