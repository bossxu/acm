//langman
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

ll dp[200][3];
int main()
{
  ios_close;
  int l,k;
  while(cin >> l >>k)
  {
    clr(dp,0);
    dp[1][1] = 1;
    dp[k][1] = 1;
    for(int i = 2;i<=l;i++)
    {
      dp[i][1] += dp[i-1][0];
      dp[i][0] += dp[i-1][1];
      if(i > k)
      dp[i][1] += dp[i-k][0];
    }
    ll sum = 0;
    for(int i = 1;i<=l;i++)
    {
      sum += dp[i][1];
    }
    cout<<sum<<endl;
  }
  return 0;
}
