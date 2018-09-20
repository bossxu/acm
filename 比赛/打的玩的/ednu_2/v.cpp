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
vector<int>son[200005];
ll dp[200005];
ll num[200005];
void dfs(int st)
{
  ll op = 0;
  ll son_num = 1;
  for(int i = 0;i<son[st].size();i++)
  {
    //cout<<son[st][i]<<endl;
    dfs(son[st][i]);
    op += dp[son[st][i]];
    son_num += num[son[st][i]];
  }
  num[st] = son_num;
  dp[st] = op+son_num;
}
int main()
{
  int n;
  ios_close;
  while(cin>>n)
  {
    clr(dp,0);
    clr(num,0);
    for(int i = 1;i<=n;i++) son[i].clear();
    int par;
    for(int i = 2;i<=n;i++)
    {
      cin >> par;
      son[par].pb(i);
    }
    dfs(1);
    cout<<dp[1];
    for(int i = 2;i<=n;i++)
    {
      cout<<" "<<dp[i];
    }
    cout<<endl;
  }
  return 0;
}
