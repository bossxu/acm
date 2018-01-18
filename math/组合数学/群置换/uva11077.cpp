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
//  freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
  unsigned long long dp[25][25];
  clr(dp,0);
  dp[1][0] = 1;
  for(int i = 2;i<=22;i++)
  {
    for(int j = 0;j<i;j++)
    {
      if(j == 0)
      {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * (i-1);
    }
  }
  int a,b;

  while(cin>>a>>b && !(a==0 && b==0))
   {
     cout<<dp[a][b]<<endl;
   }
  return 0;
}
