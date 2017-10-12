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
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  int n;
  ll dp[105][105];
  int shu[104];
  while(cin>>n)
  {
    clr(dp,INF);
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      dp[i][i] = 0;
    }
    for(int j = 1;j<=n;j++)
    {
      for(int i = 1;i+j<n;i++)
      {
         for(int k = i;k<=i+j;k++)
         {
            dp[i][j+i] = min(dp[i][i+j],dp[i][k]+dp[k+1][j+i]+shu[i]*shu[k+1]*shu[i+j+1]);
         }
      }
    }
  }
  cout<<dp[1][n-1]<<endl;
  return 0;
}
