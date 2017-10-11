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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
const int maxn = 105;
// wa 的原因主要在于 对分组背包的理解不够深,没有发现自己的式子出现了 二次调用的现象
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,m;
  int dp[maxn];
  int a[maxn][maxn];
  while(cin>>n>>m)
  {
    if(!n && !m) break;

    for(int i= 1;i<=n;i++)
     for(int j=1;j<=m;j++)
       cin>>a[i][j];
    clr(dp,0);
    for(int i=1;i<=n;i++)
    {
      for(int k=m;k>=1;k--)
      {
        for(int j=1;j<=k;j++)
        {
          dp[k]= max(dp[k-j]+a[i][j],dp[k]);
        }
      }
    }
   cout<<dp[m]<<endl;
  }
  return 0;
}
