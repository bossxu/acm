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
ll s[3005];
ll c[3005];
ll dp[3005][4];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    clr(dp,INF);
    for(int i = 1;i<=n;i++)
    {
      cin>>s[i];
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>c[i];
      dp[i][1] = c[i];
    }
    ll ans = INF;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<i;j++)
      {
          if(s[i] > s[j])
          {
            for(int k = 2;k<=3;k++)
            {
              dp[i][k] = min(dp[i][k],dp[j][k-1]+c[i]);
            }
          }
      }
      ans = min(dp[i][3],ans);
    }
    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
  }

  return 0;
}
