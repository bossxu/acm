#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int R,C;

char mi[1005][1005];
int vis[1005][1005],fire[1005][1005];
struct node{
    int x,y;
    int step;
};
bool check(int x,int y)
{
    if(x<0 || y<0 || x>=R || y>=C || vis[x][y] || mi[x][y]=='#')
    {
        return false;
    }
    return true;
}

void bfs_fire()
{

   queue<node>q;
   memset(vis,0,sizeof(vis));
   memset(fire,inf,sizeof(fire));
    for(int i = 0; i < R; i++) {  
        for(int j = 0; j < C; j++) {  
            if(mi[i][j] == 'F') {  
                vis[i][j] = 1;  
                fire[i][j] = 0;
                node a;
                a.x=i;a.y=j;a.step=0;  
                q.push(a);  
            }     
        }     
    }  
   while(!q.empty())
   {
       node a = q.front();
       q.pop();
       for(int da=-1;da<=1;da++)
       {
           for(int db=-1;db<=1;db++)
           {
               if(da!=db && da+db!=0)
               {
                   if(check(a.x+da,a.y+db))
                   {
                      vis[a.x+da][a.y+db]=1;
                      node b;
                      b.x=a.x+da;
                      b.y=a.y+db;
                      b.step=a.step+1;
                      fire[b.x][b.y]=b.step;
                      q.push(b);
                   }                
               }
           }
       }
   }
}
int bfs_man(int i, int j)
{
    memset(vis,0,sizeof(vis));
    vis[i][j]=1;
    int cnt=0;
    node a;
    a.x=i;a.y=j;a.step=0;
    queue<node>q;
    q.push(a);
    while(!q.empty())
    {
        a = q.front();
        q.pop();
         for(int da=-1;da<=1;da++)
       {
           for(int db=-1;db<=1;db++)
           {
               if(da!=db && da+db!=0)
               {
                   if(a.x+da<0 || a.y+db <0 || a.x+da>=R ||a.y+db>= C) 
                        return a.step+1;
                   if(mi[a.x+da][a.y+db]=='.' && fire[a.x+da][a.y+db]>a.step+1 && vis[a.x+da][a.y+db]==0 )
                   {
                        node b;
                        vis[a.x+da][a.y+db]=1;
                        b.x = a.x+da;
                        b.y = a.y+db;
                        b.step = a.step+1; 
                        q.push(b);
                       // printf("%d %d %d\n",b.x,b.y,b.step);
                   }
               }
           }
       }   
    }
    return -1;
}
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    memset(mi,0,sizeof(mi));  
    scanf("%d%d",&R,&C);
    int i,j;
    int a,b,c,d;
    for(i=0;i<R;i++)
      scanf("%s",mi[i]);
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(mi[i][j]=='J')
              { a=i;b=j; }
            if(mi[i][j]=='F')
               { c=i;d=j ; }
        }
    }
   bfs_fire();
   /* for(i=0;i<R;i++)
   {
       for(j=0;j<C;j++)
       {
           printf(" %d", fire[i][j] );
       }
       putchar('\n');
   }*/
   int k = bfs_man(a,b);
   if(k==-1) printf("IMPOSSIBLE\n");
   else printf("%d\n",k);
  }
  //system("pause");
    return 0;
}