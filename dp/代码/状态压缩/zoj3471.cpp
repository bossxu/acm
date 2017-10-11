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
int n;
int map[12][12];
int dp[(1<<10)+10];
//好题
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>n && n)
    {
      clr(dp,0);
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          cin>>map[i][j];
      for(int i = (1<<n)-1;i>=0;i--)
      {
         for(int j = 0;j<n;j++)
         {
           if(i & (1<<j))
           {
             for(int k =0;k<n;k++)
             {
               if(k == j) continue;
               if(i & (1<<k)) continue;
               dp[i] = max(dp[i],dp[i|(1<<k)]+map[j+1][k+1]);
             }
           }
         }
      }
      int ans = 0;
      for(int i = 0;i<n;i++)
      {
        ans = max(dp[1<<i],ans);
      }
      cout<<ans<<endl;
    }

    return 0;
}
