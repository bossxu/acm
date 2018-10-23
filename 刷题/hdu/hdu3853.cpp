#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
double shu[3][1005][1005];
double dp[1005][1005];
// wa 了一次 ，少了个特判一定走到他自己的情况
int main()
{
  int r,c;
  while(scanf("%d%d",&r,&c) == 2)
  {
    for(int i = 1;i<=r;i++)
    {
      for(int j = 1;j<=c;j++)
      {
        for(int k = 0;k<3;k++)
        {
          scanf("%lf",&shu[k][i][j]);
        }
      }
    }
    clr(dp,0);
    for(int i = r;i>=1;i--)
    {
      for(int j = c;j>=1;j--)
      {
        if(i == r && j == c) continue;
        if(shu[0][i][j] == 1.00) continue;
        dp[i][j] =  1.0*(dp[i][j+1]*shu[1][i][j]+dp[i+1][j]*shu[2][i][j]+2)/(1-shu[0][i][j]);
      }
    }
    printf("%.3lf\n",dp[1][1]);
  }
  return 0;
}
/*
2 2
0.00 0.50 0.50    0.50 0.00 0.50
0.50 0.50 0.00    1.00 0.00 0.00
*/
