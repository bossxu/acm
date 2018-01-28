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
//经典的最短路劲问题 这里用的是floyd的方法，超时。
int dist[maxn][maxn];
int N;
void init()
{
    memset(dist,INF,sizeof(dist));
}
void floyd()
{
   for (int k=1; k<=N; ++k) {
  for (int i=1; i<=N; ++i) {
    for (int j=1; j<=N; ++j) {
            
      if (dist[i][k]!=INF && dist[k][j] !=INF && dist[i][k] + dist[k][j] < dist[i][j]  ) {
        dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}
}
int main()
{
   int T; 
    while(cin>>T>>N)
    {
        init();
        while(T--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            dist[a][b]=c;
            dist[b][a]=c;
        }
        floyd();
        for(int i=1;i<=N;i++)
          for(int j=1;j<=N;j++)
            {printf("%d ",dist[i][j]);
            if(j==N) printf("\n");}
        printf("%d\n",dist[1][N]);
    }
    return 0;
}