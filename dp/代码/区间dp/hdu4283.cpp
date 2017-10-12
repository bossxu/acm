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
bool cmp(int a, int b) {return a>b;}
//水题,但是题目感觉有点难理解
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t ;
  int co = 0;
  cin>>t;
  int shu[105];
  int dp[105][105];
  int n;
  int sum[105];
  while(t--)
  {
    scanf("%d",&n);
    clr(sum,0);
    for(int i =1;i<=n;i++)
    {
      cin>>shu[i];
      sum[i]=sum[i-1]+shu[i];
    }
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      for(int j = i+1;j<=n;j++)
       dp[i][j] = INF;
    }
    for(int j=1;j<=n;j++)
    {
      for(int i = 1;i+j<=n;i++)
      {
        for(int k = i;k<=i+j;k++)
        {
          dp[i][j+i] = min(dp[i][j+i],dp[i+1][k]+dp[k+1][i+j]+shu[i]*(k-i)+(sum[i+j]-sum[k])*(k-i+1));
        }
      }

    }
    printf("Case #%d: %d\n",++co,dp[1][n]);
  }
  return 0;
}
