#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;

int dp[20][20];
int main()
{
  clr(dp,0);
  int a,b,k;
  while(cin>>a>>b>>k)
  {
    dp[a][b] = k;
    for(int i = 1;i<=10;i++)
    {
      for(int j = 1;j<=10;j++)
      {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
    for(int i = 0;i<=10;i++)
    {
      cout<<i<<" -- ";
      for(int j = 1;j<=10;j++)
      {
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
