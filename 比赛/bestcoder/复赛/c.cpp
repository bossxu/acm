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
const int N = 100005;
int pre[N];
ll val[N];
ll dp[32];
ll ko[32];
vector<ll>op[N];
int find(int st)
{
  if(pre[st] == st)
    return st;
  return pre[st] = find(pre[st]);
}
void bin(int v,int u)
{
  int x = find(u),y = find(v);
  //cout<<x<<" "<<u<<" "<<y<<" "<<v<<endl;
  if(x == y) return;
  pre[x] = y;
}
int main()
{
  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  ko[0] = 1;
  for(int i = 1;i<=30;i++) ko[i] = ko[i-1]*2%mod;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
      cin>>val[i];
      pre[i] = i;
      op[i].clear();
    }
    for(int i = 1;i<=m;i++)
    {
      int u,v;
      cin>>u>>v;
      bin(u,v);
    }
    for(int i = 1;i<=n;i++)
    {
      op[find(i)].pb(val[i]);
    }
    for(int i = 1;i<=n;i++)
    {
      if(!op[i].empty())
      sort(op[i].begin(),op[i].end());
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      int len = op[i].size();
      //cout<<len<<endl;
      clr(dp,0);
      for(int j = 0;j<len;j++)
      {
        for(int k = 0;k<30;k++)
        {
          if(op[i][j] & (1<<k))
          {
            ans = (ans+(op[i][j]*dp[k]%mod)*ko[k])%mod;
            dp[k]++;
          }
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
