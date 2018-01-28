#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define inf  0x3f3f3f3f
using namespace std;
typedef long long ll;
int N,M;
char shu[202][202];
int vis[202][202],route[202][202];
struct node
{
  int x;int y;
  int deep;
};
void init()
{
    memset(route,0,sizeof(route));
}
bool check(int x,int y)
{
    if(x<0 || y<0 || x>=N||y>=M || shu[x][y]=='#' || vis[x][y])
    return false;
    return true;
}
void bfs(int i,int j)
{
   node a;
   a.x=i;a.y=j;
   a.deep= 0;
   memset(vis,0,sizeof(vis));
   vis[i][j]=1;
   queue<node>q;
   q.push(a);
   while(!q.empty())
   {
       a = q.front();
       q.pop();
       for(int da=-1;da<=1;da++)
       {
           for(int db =-1;db<=1;db++)
           {
               if(da!=db && da+db!=0 )
               {
                   int x=a.x+da;
                   int y=a.y+db;
                   if(check(x,y))
                   {
                      node b;
                      vis[x][y]=1;
                      b.x=x;b.y=y;
                      b.deep=a.deep+1;
                      route[x][y]+=b.deep;
                      q.push(b);
                   }
               }
           }
       }
   }
   /*for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
            printf("%d ",route[i][j] );
         }
         putchar('\n');
     }
     putchar('\n');*/
}
int main()
{
   while(cin>>N>>M)
   {
     int i,j;
     init();
     for(i=0;i<N;i++)
     {
         scanf("%s",shu[i]);
     }
     for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
             if(shu[i][j]=='Y')
             bfs(i,j);
             if(shu[i][j]=='M')
             bfs(i,j);
         }
     }
 /*for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
            printf("%d ",route[i][j] );
         }
         putchar('\n');
     }*/
     int ans=inf;
     for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
             if(shu[i][j]=='@' && route[i][j]!=0 )
             {
                 ans = min(ans,route[i][j]);
             }
         }
     }
     
     printf("%d\n",ans*11);
   }  
    return 0;
}