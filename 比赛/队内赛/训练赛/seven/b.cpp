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
char map[55][55];
int n,m;
int vis[55][55];
int flag;
int stx,sty;
void dfs(int x,int y,int a,int b,char s)
{
  vis[x][y] = 1;
  //cout<<x<<" "<<y<<" "<<a<<" "<<b<<map[x][y]<<endl;
  for(int i = -1;i<=1;i++)
  {
    for(int j = -1;j<=1;j++)
    {
      if(i == j || i+j == 0) continue;
      int dx = x+i,dy = y+j;
      if(dx<0 || dy<0 ||dx == n || dy == m) continue;
      if(!(dx==a && dy == b) && map[dx][dy] == s)
      {
        if(!vis[dx][dy])
          dfs(dx,dy,x,y,s);
        else
        {
          if(dx == stx && dy == sty) flag = 1;
        }
      }
    }
  }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    for(int i = 0;i<n;i++)
    {
      cin>>map[i];
    }
    flag = 0;
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<m;j++)
      {
        clr(vis,0);
        stx = i,sty = j;
        dfs(i,j,-1,-1,map[i][j]);
      }
    }
    if(flag)
    {
      cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
  }
  return 0;
}
