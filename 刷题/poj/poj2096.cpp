#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
double dp[1004][1004];
// 这题看代码好像还行，但是啊。
// 它题目没怎么说清楚。而且是网上公式给的好
// dp[i][j] 表示的是已经在j个子系统中
// 理论上应该是出现一个方程组
// 根据期望啥的。无关性能解决问题。
// poj 不支持bits
int main()
{
  int n,s;
  while(scanf("%d%d",&n,&s) == 2)
  {
      clr(dp,0);
      double ns = n*s;
      for(int i = n;i>=0;i--)
      {
        for(int j = s;j>=0;j--)
        {
          if(n == i && j == s) continue;
          dp[i][j] = 1.0*(ns+dp[i+1][j]*(n-i)*j+i*(s-j)*dp[i][j+1]+(n-i)*(s-j)*dp[i+1][j+1])/(ns-i*j);
        }
      }
      printf("%.4lf",dp[0][0]);
  }
  return 0;
}
