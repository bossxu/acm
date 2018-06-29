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
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a[i].clear();
#define pb push_back
const double eps = 1e-6;
char s[300005];
vector<int>map[300005];
int g[300005];
int dp[300005][30];
queue<int>q;
int cnt = 0;
int n,m;
//简单的拓扑序加dp
//学到的是,拓扑序的实现,以及这里的dp,我不仅可以做子状态到父亲结点的一个更新,也可以从父亲结点到字节点的一个更新
void slove()
{
  for(int i = 1 ; i<=n; i++)
  {
    if(g[i] == 0)
    {
      q.push(i);
    }
  }
  for(int i = 1;i<=n;i++)
  {
    dp[i][s[i-1]-'a'] = 1;
  }
  while(!q.empty())
  {
    int st = q.front();
    q.pop();
    cnt++;
    for(int i = 0;i<map[st].size();i++)
    {
      int to = map[st][i];
      g[to]--;
      if(g[to] == 0)
      {
        q.push(to);
      }
      for(int i = 0;i<26;i++)
      {
        if(s[to-1] - 'a'== i )
        {
          dp[to][i] = max(dp[to][i],dp[st][i]+1);
        }
        else dp[to][i] = max(dp[to][i],dp[st][i]);
      }
    }

  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin>>n>>m)
  {
    cin>>s;
    clr(g,0),clr(dp,0);
    for(int i = 1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        map[u].push_back(v);
        g[v]++;
    }
    cnt = 0;
    slove();
    if(cnt<n)
    {
      cout<<-1<<endl;
      continue;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 0;j<26;j++)
      {
        ans = max(ans,dp[i][j]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
