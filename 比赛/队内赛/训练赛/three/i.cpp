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
char s[105][105];
int vis[105][105];
int n,m;
int flag;
int check(int x,int y)
{
  if(x<0 || y<0 || x>=n || y>=m ) return 0;
  return 1;
}
void dfs1(int x,int y)
{
  vis[x][y] = 1;
  for(int i = -1;i<=1;i++)
  {
    for(int j = -1;j<=1;j++)
    {
      if(i!=j && i+j!=0)
      {
        int a = x+i;
        int b = y+j;
        if(check(a,b))
        {
          if(s[a][b] == '1' && !vis[a][b])
          {
            dfs1(a,b);
          }
        }
      }
    }
  }
}
void dfs2(int x,int y)
{
  vis[x][y] = 1;
  for(int i = -1;i<=1;i++)
  {
    for(int j = -1;j<=1;j++)
    {
      if(i!=j && i+j!=0)
      {
        int a = x+i;
        int b = y+j;
        if(check(a,b))
        {
          if(s[a][b] == '0' && !vis[a][b])
          {
            dfs2(a,b);
          }
        }
        else
        {
          flag = 0;
        }
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
     for(int i = 0;i<n;i++)
     {
       cin>>s[i];
     }
     int num1 = 0,num2 = 0;
     clr(vis,0);
     for(int i = 0;i<n;i++)
     {
       for(int j = 0;j<m;j++)
       {
         if(!vis[i][j] && s[i][j] == '1')
         {
           dfs1(i,j);
           num1++;
         }
       }
     }
     clr(vis,0);
     for(int i = 0;i<n;i++)
     {
       for(int j = 0;j<m;j++)
       {
         flag = 1;
         if(!vis[i][j] && s[i][j] == '0')
         {
           dfs2(i,j);
           if(flag)
           num2++;
         }
       }
     }
     if(num1 == 1 && num2 == 1)
     {
       cout<<0<<endl;
     }
     else if(num1 == 1 && num2 == 0)
     {
       cout<<1<<endl;
     }
     else cout<<-1<<endl;
   }
  return 0;
}
