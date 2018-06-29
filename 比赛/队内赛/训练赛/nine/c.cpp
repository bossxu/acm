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
int map[405][405];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,m;
  while(cin>>n>>m)
  {
    clr(map,INF);
    for(int i = 1;i<=m;i++)
    {
      int a,b;
      cin>>a>>b;
      map[a][b] = 1;map[b][a] = 1;
    }
    if(map[1][n] == 1)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=n;j++)
        {
          if(map[i][j] == 1) map[i][j] = INF;
          else map[i][j] = 1;
        }
      }
      for(int k = 1;k<=n;k++)
      {
        for(int i = 1;i<=n;i++)
        {
          for(int j = 1;j<=n;j++)
          {
            map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
          }
        }
      }
      if(map[1][n] == INF)
      {
        cout<<-1<<endl;
      }
      else
      cout<<map[1][n]<<endl;
    }
    else
    {
      for(int k = 1;k<=n;k++)
      {
        for(int i = 1;i<=n;i++)
        {
          for(int j = 1;j<=n;j++)
          {
            map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
          }
        }
      }
      if(map[1][n] == INF)
      {
        cout<<-1<<endl;
      }
      else
      cout<<map[1][n]<<endl;
    }
  }
  return 0;
}
