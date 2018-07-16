#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
#include<map>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll shu[100005];
vector<int>G[100005];
ll dp[100005];
ll sz[100005];
void dfs(int u,int fa)
{
  sz[u]=1;
  for(int i=0;i<G[u].size();i++)
  {
    int v=G[u][i];
    if(v == fa) continue;
    dfs(v,u);
    sz[u]+=sz[v];
  }
}
int n;
void solve(int u,int fa)
{
  //if(fa == -1)
  dp[u] = n + (n-sz[u])*(sz[u]-1);
  int ans = 1;
  int flag = 0;
  for(int i=0;i<G[u].size();i++)
  {
    int v=G[u][i];
    if(v == fa) continue;
    ans*=sz[v];
    flag++;
    solve(v,u);
  }
  if(flag == 2)
  dp[u]+=ans;

}
int gcd(int a,int b)
{
  return b == 0?a:gcd(b,a%b);
}
map<ll,int>op[2];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    clr(sz,0);
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      G[i].clear();
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int v,t;
    for(int i = 1;i<=n-1;i++)
    {
      cin>>v>>t;
      G[v].push_back(t);
      G[t].push_back(v);
    }
    dfs(1,-1);
    solve(1,-1);
    //cout<<"hello"<<endl;
    ll sum = 0;
    for(int i = 1;i<=n;i++)
    {
      //cout<<dp[i]<<endl;
      sum+=shu[i]*dp[i];
    }
    if(sum == 0)
    {
      cout<<0<<endl;
      continue;
    }
    int flag = 1;
    op[1][dp[1]] = 1;
    for(int i = 2;i<=n;i++)
    {
      for(map<ll,int>::iterator j = op[flag].begin();j!=op[flag].end();j++)
      {
        op[flag^1][j->first] = j->second;
      }
      op[flag^1][dp[i]] = 1;
      for(map<ll,int>::iterator j = op[flag].begin();j!=op[flag].end();j++)
      {
        int ko = gcd(dp[i],j->first);
        op[flag^1][j->first] = j->second;
        if(op[flag^1][ko] == 0)
        {
          op[flag^1][ko] = j->second+1;
        }
        else
        {
          op[flag^1][ko] = min(j->second+1,op[flag^1][ko]);
        }
      }
      op[flag].clear();
      flag^=1;
    }
    int ans = n;
    for(int i = 1;i<=n;i++)
    {
      if(shu[i] == 0) ans--;
    }
    if(sum<0) sum = -sum;
    for(map<ll,int>::iterator j = op[flag].begin();j!=op[flag].end();j++)
    {
      if(sum%(j->first) == 0)
      {
        ans = min(j->second,ans);
      }
    }
    op[flag].clear();
    cout<<ans<<endl;
  }
  return 0;
}
