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
int map[505][505];
int  N,M,W;
int item;
void floyd()
{
   for (int k=1; k<=N; ++k) {
    for (int i=1; i<=N; ++i) {
      for (int j=1; j<=N; ++j) {
            
      if (map[i][k]!=INF && map[k][j] !=INF && map[i][k] + map[k][j] < map[i][j]  ) {
        map[i][j] = map[i][k] + map[k][j];
      }
      if(map[i][i]<0) 
      {item=1;break;}
    }
    if(item ) break;
  }
}
}
int main()
{
  int T;cin>>T;
  while(T--)
{
    scanf("%d%d%d",&N,&M,&W);
    for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
      {
        map[i][j]=INF;
      }
    }
    for(int i=1;i<=M;i++)
    {
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        if(map[a][b]>t)
        {
          map[a][b]=t;
          map[b][a]=t;
        }
    }
    item=0;
    for(int i=1;i<=N;i++) map[i][i]=0;
    for(int i=1;i<=W;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        map[a][b]=-c;
    }
    floyd();
  if(item == 1) printf("YES\n");
  else printf("NO\n"); 
}
    return 0;
}