#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
int dp[2][2];
char sta[N];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int sum = 0;
    memset(dp,0,sizeof(dp));
    for(int i = 1;i<=n;i++)
    {
      string s;
      cin>>s;
      int top = 0;
      int len  = s.size();
      int l = s[0] == ')'?1:0;
      int r = s[len-1] == '('?1:0;
      for(int i = 0;i<len;i++)
      {
        if(top == 0)
        {
          sta[top++] = s[i];
        }
        else
        {
          if(sta[top-1] == '(' && s[i] == ')')
          {
            sum+=2;
            top--;
          }
          else
          {
            sta[top++] = s[i];
          }
        }
      }
      dp[l][r]++;
    }
    int all = max(dp[0][1],dp[1][0]);
    int op = min(dp[0][1],dp[1][0]);
    sum += op*2;
    dp[0][1] -= op;
    dp[1][0] -= op;
    int num = max(dp[0][1],dp[1][0]);
    int up = min(num,dp[1][1]);
    sum += up*2;
    dp[1][1] -= up;
    num -= up;
    if(dp[1][1] > 0 && all>0)
    {
      sum+=dp[1][1]*2;
    }
    else if(dp[1][1] > 0)
    {
      sum += (dp[1][1]-1)*2;
    }
    if(num>0)
    {
      sum += min(num,up)*2;
    }
    cout<<sum<<endl;
  }
  return 0;
}
