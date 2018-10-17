#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
double dp[30][30];
char shu[30][30];
// 看到这个题，第一感觉是建立一张225大小的方程组
// 跑高斯消元。
int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m) == 2)
  {
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        scanf("%c",&shu[i][j]);
      }
    }

  }
  return 0;
}
