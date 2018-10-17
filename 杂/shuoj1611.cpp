#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
int shu[30];
ll dp[30][30];
int n;
void dfs(int l,int r)
{
  //cout<<l<<" "<<r<<endl;
  if(l == r) cout<<"A"<<l;
  for(int i = l ;i<r;i++)
  {
    if(dp[l][r] == dp[l][i]+dp[i+1][r]+shu[l]*shu[i+1]*shu[r+1])
    {
      if(l == 1 && r == n)
      {
        dfs(l,i);
        dfs(i+1,r);
      }
      else
      {
        cout<<"(";
        dfs(l,i);
        dfs(i+1,r);
        cout<<")";
      }
      return;
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tot = 0;
  while(cin>>n)
  {
    clr(dp,INF);
    for(int i = 1;i<=n+1;i++)
    {
      cin>>shu[i];
      dp[i][i] = 0;
    }
  for(int j=1;j<=n;j++)
  {
    for(int i = 1;i+j<=n;i++)
    {
      for(int k = i;k<=i+j;k++)
      {
        dp[i][j+i] = min(dp[i][j+i],dp[i][k]+dp[k+1][i+j]+shu[i]*shu[k+1]*shu[i+j+1]);
      }
    }
  }
  cout<<"Case "<<(++tot)<<endl;
  cout<<dp[1][n]<<" ";
  dfs(1,n);
  cout<<endl;
}
  return 0;
}
