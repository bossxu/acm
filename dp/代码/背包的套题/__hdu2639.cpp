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
//  二维背包 ,想不到这样的递归方式
// 好题
// 
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  int dp[1005][31];
  int w[105],v[105];
  while(t--)
  {
    int n,m,k;
    cin>>n>>m>>k;
    clr(dp,0);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=m;j>=w[i];j--)
      {
        int a[32],b[32];
        for(int l=1;l<=k;l++)
        {
          a[l]=dp[j][l];
          b[l]=dp[j-w[i]][l]+v[i];
        }
        int s1=1,s2=1;
        a[k+1]=b[k+1]=-1;
        for(int l=1;(a[s1]!=-1 || b[s2]!=-1) && l<=k;l++)
        {
          if(a[s1]>b[s2])
          {
            dp[j][l] = a[s1++];
          }
          else
          {
            dp[j][l] = b[s2++];
          }
          if(l>1 && dp[j][l] == dp[j][l-1])
          {
            l--;
          }
        }
      }
    }
    cout<<dp[m][k]<<endl;
  }
  return 0;
}
