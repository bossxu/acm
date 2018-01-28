#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int N,M;
int vis[52][52],mi_ex[52][52];
int fa_s[4]={-1,0,1,0},fa_x[4]={0,-1,0,1};//下左上右
int s_x,s_y,e_x,e_y;
int fang;
struct node{
  int x,y;
  int f;
  int deep;
  int zhuan_1=0;
  int zhuan_2=0;
  int zhuan_3=0;
};
bool check(int x,int y)
{
    if(x<=0||y<=0 ||x>N+1||y>M ||mi_ex[x][y]!=0 || vis[x][y])
      return false;
    return true;
}
int bfs()
{
    memset(vis,0,sizeof(vis));
   queue<node>q;
   node a;
   a.x=s_x+1;
   a.y=s_y+1;
   
   vis[a.x][a.y]=1;
   a.deep = 0;
   a.f = fang; 
   q.push(a);
   while(!q.empty()) 
   {
       a=q.front();
       q.pop();
       if(a.x==e_x+1 && a.y==e_y+1)
       {
           return a.deep;
       }
       //选择转向
       if(check(a.x+fa_s[a.f] , a.y + fa_x[a.f] ))
       {
           node b;
           b.x=a.x+fa_s[a.f];b.y=a.y + fa_x[a.f];
           b.deep=a.deep+1;
           b.f=a.f;
           q.push(b);
           vis[b.x][b.y]=1;
       }
        if(check(a.x+fa_s[a.f]*2 , a.y + fa_x[a.f]*2 ) && mi_ex[a.x+fa_s[a.f] ][ a.y + fa_x[a.f]]!=1)
       {
           node b;
           b.x=a.x+fa_s[a.f]*2;b.y=a.y + fa_x[a.f]*2;
           b.deep=a.deep+1;
           b.f=a.f;
           q.push(b);
           vis[b.x][b.y]=1;
       }
       if(check(a.x+fa_s[a.f]*3 , a.y + fa_x[a.f]*3 ) && mi_ex[a.x+fa_s[a.f]*2 ][ a.y + fa_x[a.f]*2]!=1 &&mi_ex[a.x+fa_s[a.f] ][ a.y + fa_x[a.f]]!=1)
       {
           node b;
           b.x=a.x+fa_s[a.f]*3;b.y=a.y + fa_x[a.f]*3;
           b.deep=a.deep+1;
           b.f=a.f;
           q.push(b);
           vis[b.x][b.y]=1;
       }
       if(a.zhuan_1!=1)
       {
          node b;
          b.x=a.x;b.y=a.y;b.deep=a.deep+1;
          b.f = (a.f+1)%4;
          b.deep = a.deep+1;
          a.zhuan_1=1;
          q.push(b);
       }
       if(a.zhuan_2!=1)
       {
            node b;
          b.x=a.x;b.y=a.y;b.deep=a.deep+1;
          b.f = (a.f+3)%4;
          b.deep = a.deep+1;
          a.zhuan_2=1;
          q.push(b);
       }
       if(a.zhuan_3!=1)
       {   
          node b;
          b.x=a.x;b.y=a.y;b.deep=a.deep+1;
          b.f = (a.f+2)%4;
          b.deep = a.deep+2;
          a.zhuan_3=1;
          q.push(b);
       }
   }
   return 0;
}
int main()
{
   while(cin>>N>>M)
    {
        if(N==0 && M==0) break;
        int i,j,t;
        memset(mi_ex,0,sizeof(mi_ex));
        for(i=1;i<=N;i++)
        {
          for(j=1;j<=M;j++)
          {
            cin>>t;
            if(t==1) 
            {
                mi_ex[i][j]=1;
                mi_ex[i][j+1]=1;
                mi_ex[i+1][j]=1;
                mi_ex[i+1][j+1]=1;
            }   
          }
        }
        
       cin>>s_x>>s_y>>e_x>>e_y;
       char c[10];
       gets(c);
       switch(c[0])
       {
           case 's': fang=0;break;
           case 'w': fang=1;break;
           case 'n': fang =2;break;
           case 'e': fang =3;break;
       }
        int k = bfs();
        printf("%d\n",k);

    }
    system("pause");
    return 0;
}