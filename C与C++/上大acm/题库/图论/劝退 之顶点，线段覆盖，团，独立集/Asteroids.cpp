#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int N;
int v1,v2;
int map[505][505];
int vis[505],link[505];
int ans;
void init()
{
    memset(map,0,sizeof(map));
    memset(link,0,sizeof(link));
    ans=0;
}
int dfs(int x)
{
  for(int i=1;i<=v2;i++)
  {
      if(map[x][i] && !vis[i])
      {
          vis[i]=1;
          if(link[i]==0 || dfs(link[i]))
          {
              link[i]=x;
              return 1;
          }
      }
      return 0;
  }
}
void search()
{
    for(int i =1;i <= v1;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs[i])
           ans++;
    }
}
int main()
{
   int T,a,b;
   while(cin>>N>>T)
   {
       v1=v2=N;
       init();
       while(T--)
       {
           scanf("%d%d",&a,&b);
           map[a][b]=1;
       }
       search();
       printf("%d\n",ans);
   }
   return 0;
}