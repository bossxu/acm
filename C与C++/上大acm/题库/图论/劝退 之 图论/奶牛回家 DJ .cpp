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
int route[maxn][maxn];
int N;
void init()
{
    memset(route,INF,sizeof(route));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j)
            route[i][j]=0;
        }
    }
}
void dijkstra()//求用邻接矩阵a表示的有向网中从Vk到其他各顶点最短路径  
{  
   int i,j,min,v,n=N;
   int dist[maxn];
   bool vis[maxn];
   for(i=1;i<=N;i++)
   {
       dist[i]=route[1][i];
       vis[i]=0;
   }
    dist[1]=0;
    vis[1]=1;
     for(i=1;i<=n;i++){  
         min=INF;  
        for(j=1;j<=n;j++)  
            if(!vis[j] && dist[j]<min){  
                v=j;  
                min=dist[j];  
            }  
        vis[v]=1;  
  
        for(j=1;j<=n;j++)  
            if(!vis[j] && dist[j]>route[v][j]+dist[v])  
                dist[j]=route[v][j]+dist[v];  
    }  
   printf("%d\n",dist[n]);
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
           if(route[a][b]>c)
           { route[a][b]=c;
            route[b][a]=c;}
        }
         dijkstra();
    }
    return 0;
}