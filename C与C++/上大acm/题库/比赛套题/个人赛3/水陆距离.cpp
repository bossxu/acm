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
const double eps = 1e-6;
char map[805][805];
int dp[805][805];
int n,m;
struct node{
    int x,y;
    int rank=0;
};
void bfs()
{
    queue<node>q;
     for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(map[i][j]=='0')
              {
                node a;
                a.x=i,a.y=j;
                 dp[i][j]=0;
                 q.push(a);
              }
              else
              dp[i][j]=1000000;
          }
      }
   while(!q.empty())
   {
      node a=q.front();
       q.pop();
       for(int dx=-1;dx<=1;dx++)
       {
           for(int dy=-1;dy<=1;dy++)
           {
              if(dx!=dy && dx+dy!=0)
              {
                  int z = a.x+dx;
                  int c = a.y+dy;
                  if(z<0 || z>=n ||c<0 ||z>=m) continue;
                  if( dp[a.x][a.y]+1<dp[z][c])
                      {
                        node b;
                        b.x=z;
                        b.y=c;
                        b.rank=a.rank+1;
                        q.push(b);
                        dp[z][c]=dp[a.x][a.y]+1;
                      }
                  
              }
           }
        }
   }
}
int main()
{
    scanf("%d%d",&n,&m);
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              cin>>map[i][j];
          }
      }
     bfs();
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<m-1;j++)
         {
             printf("%d ",dp[i][j]);
         }
         printf("%d\n",dp[i][m-1]);
      }
      //system("pause");
    return 0;
}