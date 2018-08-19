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
int shu[207][207];
int dp[205];
int n,m;
int ans;
void check()
{
  for(int i = 1;i<=n;i++)
  {
    int op = dp[i];
    for(int j = 1;j<=m;j++)
    {
      shu[i][j] = op%2;
      op/=2;
    }
  }
  int op = 0;
  for(int i = 1;i<=n;i++)
  {
    stack<int>q;
    for(int j = 1;j<=m;j++)
    {
      if(q.empty() || shu[i][j] == 0)
      {q.push(shu[i][j]);continue;}
      if(shu[i][j] == 1)
      {
        if(q.top() == 0)
        q.pop();
        else
        q.push(shu[i][j]);
      }
    }
    if(q.empty()) op++;
  }
  for(int i = 1;i<=m;i++)
  {
    stack<int>q;
    for(int j = 1;j<=n;j++)
    {
      if(q.empty() || shu[j][i] == 0)
      {q.push(shu[j][i]);continue;}
      if(shu[j][i] == 1)
      {
        if(q.top() == 0)
        q.pop();
        else
        q.push(shu[j][i]);
      }
    }
    if(q.empty()) op++;
  }
  ans = max(op,ans);
}
void dfs(int st)
{
  //cout<<st<<endl;
  if(st == n+1)
  {
    check();
    return;
  }
  for(int i = 0;i<(1<<m);i++)
  {
    dp[st] = i;
    dfs(st+1);
  }
}
int main()
{
  while(cin>>n>>m)
  {
    ans = 0;
    dfs(1);
    cout<<ans<<endl;
  }
  return 0;
}
