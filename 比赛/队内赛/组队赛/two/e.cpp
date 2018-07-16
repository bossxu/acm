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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int map[505][505];
int vis[505][505];
ll ans;
int n,m;
struct node
{
  int x,y;
};
struct cmp{
  bool operator()(node a, node b)
  {
    return map[a.x][a.y]>map[b.x][b.y];
  }
};
void bfs(int stx, int sty)
{
  vis[stx][sty] = 1;
  priority_queue<node,vector<node>,cmp>q;
  node a;
  a.x = stx,a.y = sty;
  q.push(a);
  while(!q.empty())
  {
    node tot = q.top();
    q.pop();
    int x = tot.x , y = tot.y;
    //cout<<x<<" "<<y<<endl;
    for(int dx = -1;dx<=1;dx++)
    {
      for(int dy = -1;dy<=1;dy++)
      {
        int tox = dx+x,toy = dy+y;
        if(tox == x && toy == y) continue;
        if(tox == 0 || toy == 0 || tox>n || toy>m || vis[tox][toy]) continue;
        if(map[tox][toy]>=0)
        {
          continue;
        }
        map[tox][toy] = max(map[tox][toy],map[x][y]);
        vis[tox][toy] = 1;
        a.x = tox,a.y = toy;
        q.push(a);
      }
    }
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  while(cin>>n>>m)
  {
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        cin>>map[i][j];
      }
    }
    ans = 0;
    int stx,sty;
    cin>>stx>>sty;
    bfs(stx,sty);
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        //cout<<map[i][j]<<" ";
        if(map[i][j]<0&&vis[i][j]!=0)
        {
          ans-=map[i][j];
        }
      }
      //cout<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}
