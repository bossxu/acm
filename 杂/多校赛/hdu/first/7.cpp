#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
int dp[200];
int ans[200];
void init()
{
  dp[1] = dp[2] = 1;
  for(int i = 3;i<=100;i++)
  {
    dp[i] = dp[i-dp[i-1]] + dp[i-1-dp[i-2]];
    ans[i] = dp[i-dp[i-1]];
  }
  ans[2] = 1;
  for(int i = 2;i<=100;i++)
  {
    dp[i]+=dp[i-1];
    ans[i]+=ans[i-1];
  }

}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  freopen("out.txt","w",stdout);
  init();
  while(t--)
  {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      cout<<ans[i]<<",";
      if(i%10 == 0)
      cout<<endl;
    }
  }
  return 0;
}
