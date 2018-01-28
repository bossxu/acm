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
int n,cun;
struct st{
int x,y;
}node[505];

float map[505][505];
float dp[505];
bool visit[505];
float suan(st a,st b)
{
    float f = a.x-b.x;
    float g = a.y-b.y;
    return sqrt(f*f+g*g);
}
void init()
{
    float ans=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            map[i][j]= suan(node[i],node[j]);
            map[j][i]= map[i][j];
            if(map[i][j]<ans) 
             { cun = i; ans=map[i][j];}
        }
    }
}
int prime(int cur)
{
    int index;
    int k=1;
    float dist[505];
    memset(visit, false, sizeof(visit));
    visit[cur] = true;
    for(int i = 1; i <= n; i ++){
        dist[i] = map[cur][i];    
    }
    
    for(int i = 1; i <= n; i ++){
        
        float mincost = INF;
        for(int j = 1; j <= n; j ++){
            if(!visit[j] && dist[j] < mincost){
                mincost = dist[j];
                index = j;    
            }    
        }
        
        visit[index] = true;
        dp[k++]=mincost;
        for(int j = 1; j <= n; j ++){
            if(!visit[j] && dist[j] > map[index][j]){
                dist[j] = map[index][j];
            }    
        }    
    } 
} 
bool cmp(float a,float b)
{
    if(a>b) return true;
    else return false;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       int a;
       cin>>a>>n;
       for( int i=1;i<=n;i++)
       {
           scanf("%d%d",&node[i].x,&node[i].y);
       }
       init();
       prime(cun);
       sort(dp+1,dp+n,cmp);
       
       printf("%.2f\n",dp[a]);
    }
    return 0;
}