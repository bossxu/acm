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
char map[20][20];
int dp[1<<15][20];
struct Node
{
  int x, y;
  int flag ;
}st[17],en[17];
int n,m;
int vis[20][20];
int step[20][20];
int op[20][20];
void bfs(int x,int y)
{
  vis[x][y] = 1;
  queue<Node> st;
  Node a;a.x = x,a.y = y;
  a.flag = 0;
  st.push(a);
  step[x][y] = 0;
  while(!st.empty())
  {
    Node p = st.front();st.pop();
    //cout<<p.x<<" "<<p.y<<endl;
    for(int i = -1;i<=1;i++)
    {
      for(int j = -1;j<=1;j++)
      {
        if(i+j == 0 || i == j) continue;
        int dx = p.x+i,dy = p.y+j;
        if(dx<0 || dy<0 || dx == n ||dy == n || vis[dx][dy] || map[dx][dy] == '#') continue;
        vis[dx][dy] = 1;
        Node l;
        l.x = dx,l.y = dy,l.flag = p.flag+1;
        step[dx][dy] = l.flag;
        st.push(l);
      }
    }
  }

}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   while(cin>>n>>m)
   {
     //clr(map,0);
     clr(dp,INF);
     for(int i = 0;i<n;i++)
     {
      cin>>map[i];
     }
     for(int j = 1;j<=m;j++)
     {
       cin>>st[j].x>>st[j].y>>en[j].x>>en[j].y;
     }
     for(int i = 1;i<=m;i++)
     {
       clr(vis,0);
       clr(step,INF);
       bfs(en[i].x-1,en[i].y-1);
       //cout<<"---"<<endl;
       for(int j = 1;j<=m;j++)
       {
         op[i][j] = step[st[j].x-1][st[j].y-1];
       }
     }
     for(int j = 0;j<m;j++)
     {
       dp[1<<j][j+1] = 0;
     }
     for(int i = 0;i<(1<<m);i++)
     {
       for(int k = 0;k<m;k++)
       {
         //cout<<(1<<k)<<endl;
         if(dp[i][k+1] == INF) continue;
         for(int j = 0;j<m;j++)
         {
           if((i&(1<<j)) || op[k+1][j+1] == INF) continue;
           dp[i|(1<<j)][j+1] = min(dp[i|(1<<j)][j+1],dp[i][k+1]+op[k+1][j+1]);
         }
       }

     }
     int ans = INF;
     for(int i = 1;i<=m;i++)
     {
       ans = min(ans,dp[(1<<m)-1][i]);
     }
     if(ans == INF) cout<<-1<<endl;
     else
     cout<<ans<<endl;
   }
  return 0;
}
