#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
const int N =  1e6+5;
vector<int> G[N];
// 感觉这题的一个记录没想到，有个点没有注意到，就是那个他的那个环顶多用一次奇数环。
struct node
{
  int flag;
  int s;
  node(int a,int b)
  {
    s = a,flag = b;
  }
  node(){}
};
queue<node> q;
int vis[N][4];
int out[N];
int shu[N];
int dfs(int st)  //判环
{
  shu[st] = 1;
  for(int i = 0;i<G[st].size();i++)
  {
    if(shu[G[st][i]] == 1) return 1;
    else if (shu[G[st][i]] == 0 && dfs(G[st][i])) return 1;
  }
  shu[st] = 2; // 这个的目的在于防止有可能有的点走了两次。
  return 0;
}
int bfs(int st)
{
  clr(vis,0);
  vis[st][0] = -1;
  node a(st,0);
  q.push(a);
  while(!q.empty())
  {
    node b = q.front();
    q.pop();
    for(int i = 0;i<G[b.s].size();i++)
    {
      if(vis[G[b.s][i]][b.flag^1]) continue;
      vis[G[b.s][i]][b.flag^1] = b.s;
      node o(G[b.s][i],b.flag^1);
      q.push(o);
    }
  }
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,m;
  while(cin >> n >> m)
  {
    int flag = 0;
    clr(shu,0);
    for(int i = 1;i<=n;i++)
    {
      G[i].clear();
      cin>>out[i];
      for(int j = 1;j<=out[i];j++)
      {
        int to;cin>>to;
        G[i].pb(to);
      }
    }
    int st;cin>>st;
    bfs(st);
    for(int i = 1;i<=n;i++)
    {
      if(out[i] == 0 && vis[i][1])
      {
        flag = 1;
        cout<<"Win"<<endl;
        vector<int> ans;
        int item = 1;
        int k = vis[i][item];ans.pb(i);
        while(k!=-1)
        {
          ans.pb(k);
          item^=1;
          k = vis[k][item];
        }
        for(int j = ans.size()-1;j>=0;j--)
        {
          cout<<ans[j]<<" ";
        }
        cout<<endl;
        break;
      }
    }
    if(!flag)
    {
      if(!dfs(st)) cout<<"Lose"<<endl;
      else cout<<"Draw"<<endl;
    }

  }

  return 0;
}
