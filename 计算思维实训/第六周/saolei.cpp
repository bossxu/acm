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
int n,m;
char map[505][505];
bool check(int x,int y)
{
  if(x<0 || y<0 ||x==n || y==m)
  {
    return 0;
  }
  if(map[x][y] == 'x')
  {
    return 1;
  }
  return 0;
}
void dfs(int x,int y)
{
  int num = 0;
  if(map[x][y] == 'x')
  return;
  for(int i =-1;i<2;i++)
  {
    for(int j = -1;j<2;j++)
    {
      if(i == 0 && j == 0)
      continue;
      num+=check(x+i,y+j);
    }
  }
  map[x][y] = num + '0';
}
int main()
{
   while(cin>>n>>m)
   {
     if(!n && !m)
     break;
     for(int i = 0;i<n;i++)
     {
       scanf("%s",map[i]);
       getchar();
     }

   for(int i = 0;i<n;i++)
   {
     for(int j = 0;j<m;j++)
     {
       dfs(i,j);
     }
   }
   for(int i = 0;i<n;i++)
   {
     for(int j = 0;j<m;j++)
     {
       cout<<map[i][j];
     }
     cout<<endl;
   }
 }
  return 0;
}
