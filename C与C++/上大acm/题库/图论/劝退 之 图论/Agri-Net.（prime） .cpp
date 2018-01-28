#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
//   构造最小生成树 之 prime 算法
bool visit[105];
int map[105][105],dist[105];
int N;
int prime(int cur)
{
    int index;
    int sum = 0;
    memset(visit, false, sizeof(visit));
    visit[cur] = true;
    for(int i = 0; i < N; i ++){
        dist[i] = map[cur][i];    
    }
    
        for(int i = 1; i < N; i ++){
        int mincost = INF;
        for(int j = 0; j < N; j ++){
            if(!visit[j] && dist[j] < mincost){
                mincost = dist[j];
                index = j;    
            }    
        }
        
        visit[index] = true;//标记已经走了
        sum += mincost;
        
        for(int j = 0; j < N; j ++){//更新最短路径
            if(!visit[j] && dist[j] > map[index][j]){
                dist[j] = map[index][j];
            }    
        }    
    } 
    return sum;    
} 
int main()
{
    
    while(cin>>N)
    {
        int i,j;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        int ans = prime(0);
        printf("%d\n",ans);
    }
    return 0;
}