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
int map[1005][1005];
ll dp1[1005][1005];
ll dp2[1005][1005];
ll dp3[1005][1005];
ll dp4[1005][1005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,m;
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        cin>>map[i][j];
      }
    }
    clr(dp1,0);
    clr(dp2,0);
    clr(dp3,0);
    clr(dp4,0);
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+map[i][j];
      }
    }
    for(int i = n;i>=1;i--)
    {
      for(int j = 1;j<=m;j++)
      {
        dp2[i][j] = max(dp2[i+1][j],dp2[i][j-1])+map[i][j];
      }
    }
    for(int i = n;i>=1;i--)
    {
      for(int j = m;j>=1;j--)
      {
        dp3[i][j] = max(dp3[i+1][j],dp3[i][j+1])+map[i][j];
      }
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = m;j>=1;j--)
      {
        dp4[i][j] = max(dp4[i-1][j],dp4[i][j+1])+map[i][j];
      }
    }
    ll ans = 0;

    for(int i = 2;i<n;i++)
    {
      for(int j = 2;j<m;j++)
      {
         ll be = max(dp1[i-1][j]+dp3[i+1][j]+dp2[i][j-1]+dp4[i][j+1],dp2[i+1][j]+dp4[i-1][j]+dp1[i][j-1]+dp3[i][j+1]);
         ans = max(be,ans);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
