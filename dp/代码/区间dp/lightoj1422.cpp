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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,co = 0;
    cin>>t;
    int n;
    int a[105];
    int dp[105][105];
    while(t--)
    {
      cin>>n;
      clr(dp,0);
      for(int i = 1;i<=n;i++)
      {
        dp[i][i] = 1;
        scanf("%d",&a[i]);
      }
      for(int j = 1;j<=n;j++)
      {
        for(int i = 1;i+j<=n;i++)
        {
          dp[i][i+j] = dp[i+1][j+i]+1;
          for(int k =i+1;k<=i+j;k++)
          {
            if(a[k] == a[i])
            dp[i][i+j] = min(dp[i][k-1]+dp[k][i+j]-1,dp[i][j+i]);
          }
        }
      }
      printf("Case %d: %d\n",++co,dp[1][n]);
    }
    return 0;
}
