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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int ans;
char map[8][8];
bool vis[8][8];
bool check(int x, int y)
{
  if(x<0 || y<0 || x>=8 || y>=8 )
  return false;
  if(map[x][y]=='K' || map[x][y]=='O'|| vis[x][y])
  return false;

   return true;
}
void dfs(int x, int y,int k)
{
  cout<<ans<<endl;
  for(int x0 = -1;x0 <= 1; x0++)
  {
    for(int y0 = -1;y0 <=1 ;y0++)
    {
      if(x0==0 && y0==0)
      continue;
      int a = x+x0,b=y+y0;
      if(check(a,b));
      {
        vis[a][b]=1;
        ans = max(k,ans);
        dfs(a,b,k+1);
        vis[a][b]=0;
      }
    }
  }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     ans = 0;getchar();
    for(int i=0;i<8;i++)
      for(int j=0;j<=8;j++)
       scanf("%c",&map[i][j]);

  /*  for(int i=0;i<8;i++)
      {
        for(int j=0;j<8;j++)
        {
          cout<<map[i][j];
        }
        cout<<endl;
      }*/
    clr(vis , 0);
    int x,y;
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(map[i][j]=='K')
        {
          x=i,y=j;
        }
      }
    }
    vis[x][y]=1;
   dfs(x,y,0);

    cout<<ans<<endl;
   }
  return 0;
}
