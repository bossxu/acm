#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 998244353;
const double eps = 1e-6;
ll dp[1005][2005][4];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  clr(dp,0);
  dp[1][1][0] =dp[1][1][3] = dp[1][2][2] = dp[1][2][1] = 1 ;
  for(int i = 2;i<=1000;i++)
  {
    dp[i][1][3] =dp[i][1][0]=1;
    for(int j = 2;j<=i*2;j++)
    {
      dp[i][j][0] = (dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3]+dp[i-1][j][0])%mod;
      dp[i][j][3] = (dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][0]+dp[i-1][j][3])%mod;
      dp[i][j][1] = (dp[i-1][j-1][0]+dp[i-1][j-1][3]+dp[i-1][j][1]+dp[i-1][j-2][2])%mod;
      dp[i][j][2] = (dp[i-1][j-1][0]+dp[i-1][j-1][3]+dp[i-1][j][2]+dp[i-1][j-2][1])%mod;
    }
  }
  while(cin>>n>>k)
  {
    ll ans = 0;
    for(int i = 0;i<4;i++)
    {
      //cout<<dp[n][k][i]<<" ";
      ans += dp[n][k][i];
    }
    cout<< (ans%mod)<<endl;
  }
  return 0;
}
