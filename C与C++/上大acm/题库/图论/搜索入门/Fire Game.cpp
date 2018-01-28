#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
int N,M;
int vis[12][12];
char shou[12][12];
//   很经典的bfs 问题
struct node
{
  int x,y;
  int deep;
};
vector<node>grass;
bool check_empty()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(shou[i][j]=='#' && !vis[i][j])
            {
                return false;
            }
        }
    }
    return true;   
}
bool check_can(int x,int y)
{
    if(x<0 || y<0 || x>=N || y>=M || vis[x][y] || shou[x][y]!='#')
    {
        return false ;
    }
    return true;
}

void init()
{
  grass.clear();
  memset(vis,0,sizeof(vis));
}
int bfs( node a, node b)
{
   memset(vis,0,sizeof(vis));
   queue<node>q;
   vis[a.x][a.y]=vis[b.x][b.y]=1;
   a.deep=b.deep=0;
   q.push(a);
   q.push(b);
   int ans =inf;int cas=1;
   while(! q.empty())
   {
       a = q.front();
       q.pop();
       ans = a.deep;
       for(int dl=-1;dl<=1;dl++)
       {
           for(int dr =-1;dr<=1;dr++)
           {
               if(dl!=dr && dl+dr!=0)
               {
                   b.x=a.x+dl;
                   b.y=a.y+dr;
                  if(check_can(b.x,b.y))
                  {
                     b.deep=a.deep+1;
                     vis[b.x][b.y]=1;
                     q.push(b);
                  }
               }
           }
       }
   }
   return ans;
}

int main()
{
   int T;
   cin>>T;
   int ca=0;
   while(T--)
   {
      int i,j;
      char c;
      cin>>N>>M;
      init();
      for(i=0;i<N;i++)
      {
          scanf("%s",shou[i]);
      }
      for(i=0;i<N;i++)
      {
         for(j=0;j<M;j++)
         {
             if(shou[i][j]=='#')
             {
                node a;
                a.x=i;a.y=j;
                a.deep=0;
                grass.push_back(a);
             }  
         }
      }
      int ans = inf;
      for(i=0;i<grass.size();i++)
      {
           for(j=i;j<grass.size();j++)
           {
                grass[i].deep=0;
                grass[j].deep=0;
                int temp = min(bfs(grass[i],grass[j]),ans);
                if(check_empty())
                {
                    ans = min(ans,temp);
                }
           }
      }      
     printf("Case %d: ",++ca);
     if(ans ==inf)
         printf("-1\n");
     else 
         printf("%d\n",ans);
   }
   //system("pause");
    return 0;
}