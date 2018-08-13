#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
char s1[100005];
char s2[100005];
int dp[2][2];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    cin>>s1>>s2;
    clr(dp,0);
    for(int i = 0;i<n;i++)
    {
      dp[s1[i]-'0'][s2[i]-'0']++;
    }
    ll num = 0;
    for(int i = 0;i<n;i++)
    {
      int a = s1[i]-'0';
      int b = s2[i]-'0';
      if(b && a)
      {
        num += dp[0][0];
      }
      if(!b && !a)
      {
        num += dp[1][1] + dp[1][0];
      }
      if(b && !a)
      {
        num += dp[1][0];
      }
      if(!b && a)
      {
        num += dp[0][0]+dp[0][1];
      }
    }
    cout<<num/2<<endl;
  }
  return 0;
}
