#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 505
using namespace std;
typedef long long ll;
bool visit[maxn];
int graph[maxn][maxn],dist[maxn];
int N;
int prime(int cur)
{
    int index;
    int ans = 0;
    memset(visit, false, sizeof(visit));
    visit[cur] = true;
    for(int i = 0; i < N; i ++){
        dist[i] = graph[cur][i];    
    }
    
    for(int i = 1; i < N; i ++){
        
        int mincost = INF;
        for(int j = 0; j < N; j ++){
            if(!visit[j] && dist[j] < mincost){
                mincost = dist[j];
                index = j;    
            }    
        }
        
        visit[index] = true;
        ans = max(ans,mincost);
        for(int j = 0; j < N; j ++){
            if(!visit[j] && dist[j] > graph[index][j]){
                dist[j] = graph[index][j];
            }    
        }    
    } 
    return ans;    
} 
int main()
{
   int T;
   cin>>T; 
    while(T--)
    {
        cin>>N;
        int i,j;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                scanf("%d",&graph[i][j]);
            }
        }
        int ans = prime(0);
        printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}