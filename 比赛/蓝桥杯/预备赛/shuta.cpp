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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   int n;
   int map[105][105];
   while(t--)
   {
     cin>>n;
     for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=i;j++)
       {
         cin>>map[i][j];
       }
     }
     int dp[105][105];
     clr(dp,0);
     dp[1][1] = map[1][1];
     for(int i = 2;i<=n;i++)
     {
        for(int j = 1;j<=i;j++)
        {
          if(j == 1)
          {
            dp[i][j] = dp[i-1][j]+map[i][j];
          }
          dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + map[i][j];
        }
     }
     int maxn = 0;
     for(int i = 1;i<=n;i++)
     {
       maxn = max(maxn,dp[n][i]);
     }
     cout<<maxn<<endl;
   }

  return 0;
}
