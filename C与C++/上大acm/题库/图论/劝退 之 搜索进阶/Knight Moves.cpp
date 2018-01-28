#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int vis[10][10];
int da[8]={-2,-2,-1,-1,1,1,2,2},db[8]={1,-1,2,-2,2,-2,1,-1};
struct qi{
    char c;
    int l,deep;
};
int bfs(qi a,qi b)
{
    queue<qi>q;
    memset(vis,0,sizeof(vis));
    vis[a.c-'a'][a.l]=1;
    a.deep=0;
    q.push(a);
    while(!q.empty())
    {
      a=q.front();
      q.pop();
       if (a.c==b.c && a.l==b.l)
            return a.deep;
      for( int i=0;i<8;i++)
      {
          char x =a.c+da[i];
          int y =a.l+db[i];
          if(x<'a' || x>'h' || y<=0 || y>8 || vis[x-'a'][y]) 
             continue;
          
             //printf("%c %d  %d  %c  %d %d %d\n",x,y,a.deep+1,b.c,b.l,da[i],db[i]);
          vis[x-'a'][y]=1;
          qi en;
          en.c=x;
          en.l=y;
          en.deep = a.deep+1;
          q.push(en);
      }       
    } 
}
int main()
{

   qi a,b;
   int i,j;
  // for(i=0;i<8;i++) printf("(%d  %d)",da[i],db[i]);
   while(scanf("%c%d %c%d",&a.c,&a.l,&b.c,&b.l)==4)
   {
       getchar();
      int k= bfs(a,b);
      printf("To get from %c%d to %c%d takes %d knight moves.\n",a.c,a.l,b.c,b.l,k);
   }
    return 0;
}