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
ll dp[30][15];
int shu[50];
int tot;
void init(ll a)
{
  tot = 0;
  while(a)
  {
    shu[tot++] = a%10;
    a/=10;
  }
}
void inital()
{
  clr(dp,0);
  dp[0][0] = 1;
  dp[0][1] = 9;
  for(int i = 1;i<=20;i++)
  {
    dp[i][0] = 1;
    for(int j = 1;j<=3;j++)
    {
      dp[i][j] = dp[i-1][j] + 9*dp[i-1][j-1];
    }
  }
  for(int i = 0;i<=20;i++)
  {
    for(int j = 1;j<=3;j++)
    {
      dp[i][j] += dp[i][j-1];
    }
  }
}
ll dfs(int len,int num,int flag)
{
  if(num > 3) return 0;
  if(len<0) return (num<=3);
  if(!flag) return dp[len][3-num];
  int Max = flag?shu[len]:9;
  ll ans = 0;

  for(int i = 0;i<=Max;i++)
  {
    if(i == 0)
    ans += dfs(len-1,num,!Max);
    else
    ans += dfs(len-1,num+1,flag&&i==Max);
  }
  return ans;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  inital();
  while(t--)
  {
    ll l,r;
    cin>>l>>r;
    //cout<<dp[l][r]<<endl;
    init(r);
    ll ans = dfs(tot-1,0,1);
    init(l-1);
    ll op = dfs(tot-1,0,1);
    cout<<ans-op<<endl;
  }
  return 0;
}
