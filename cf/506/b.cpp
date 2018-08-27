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
const int mod = 1e9+7;
const double eps = 1e-6;
ll shu[200005];
int dp[200005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    dp[n+1] = 0;
    dp[n] = 1;
    int maxn = 1;
    for(int i = n-1;i>=1;i--)
    {
      if(shu[i]*2 >= shu[i+1])
      {
        dp[i] = dp[i+1]+1;
      }
      else
      dp[i] = 1;
      //cout<<i<<" "<<dp[i]<<endl;
      maxn = max(maxn,dp[i]);
    }
    cout<<maxn<<endl;
  }
  return 0;
}
