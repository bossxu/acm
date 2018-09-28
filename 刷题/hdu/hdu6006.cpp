#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case #"<<x<<": "
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
// 估计错误的原因在于一个dp的方向错了，有些重复利用了
// 唉，下次还是不要投机取巧了，上次网络赛也有题可能是这样的原因导致的
vector<int>a[13];
vector<int>b[13];
vector<int>c[13];
void init()
{
  for(int i = 0;i<=10;i++)
  {
    a[i].clear();
    b[i].clear();
    c[i].clear();
  }
}
int dp[12][(1<<10)+5];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t; cin>>t;
  int n,m;
  int tot = 0;
  clr(dp,0);
  while(t--)
  {
    init();
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
      int num;cin>>num;
      for(int j = 1;j<=num;j++)
      {
        int op;cin>>op;
        a[i].pb(op);
      }
    }
    for(int i = 0;i<m;i++)
    {
      int num;cin>>num;
      for(int j = 1;j<=num;j++)
      {
        int op;cin>>op;
        c[i].pb(op);
      }
    }
    int vis[102];
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<(1<<m);j++)
      {
        clr(vis,0);
        for(int k = 0;k<m;k++)
        {
          if(j&(1<<k))
          {
            for(int l = 0;l<c[k].size();l++)
            vis[c[k][l]] = 1;
          }
        }
        int flag = 1;
        for(int k = 0;k<a[i].size();k++)
        {
          if(!vis[a[i][k]]) flag = 0;
        }
        if(flag)
        b[i].pb(j);
      }
    }
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      for(int k = 0;k<(1<<m);k++)
      {
        int len = b[i].size();
        for(int j = 0;j<len;j++)
        {
          if((k|b[i][j]) == k)
          dp[i][k] = max(dp[i-1][k-b[i][j]]+1,dp[i][k]);
        }
        dp[i][k] = max(dp[i][k],dp[i-1][k]);
      }
    }
    int maxn = 0;
    for(int i = 1;i<(1<<m);i++)
    {
      maxn = max(dp[n][i],maxn);
    }
    c_fuck(++tot);
    cout<<maxn<<endl;
  }
  return 0;
}
