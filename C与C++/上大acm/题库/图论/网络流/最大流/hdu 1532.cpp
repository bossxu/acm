#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
const int maxn = 205;
// 知识点分解： 最大流
// Dinic 模版
int n,m;
int st,en;
struct Dinic  
{  
    int c;  
    int f;  
}edge[maxn][maxn];  
int level[maxn],iter[maxn];
bool dinic_bfs(int M)//构造层次网络  
{  
    queue<int> Q;  
    memset(level,0,sizeof(level));//初始化顶点的层次 为0  
    Q.push(1);  
    level[1]=1;  
    int u,v;  
    while(!Q.empty())  
    {  
        u=Q.front();  
        Q.pop();  
        for(v=1;v<=M;v++)  
        {  
            if(!level[v]&&edge[u][v].c>edge[u][v].f)//即顶点未被访问过，顶点u，v,存在边  
            {  
                level[v]=level[u]+1;//给顶点标记层次  
                Q.push(v);  
            }  
        }  
    }  
    return level[M]!=0;//若返回false表明 汇点不在层次网络中  
}  
int dinic_dfs(int u,int M,int cp)//进行增广  //u起 M终 cp 边长
 {  
    int tmp=cp;  
    int v,t;  
    if(u==M)  
        return cp;  
    for(v=1;v<=M&&tmp;v++)  
    {  
        if(level[u]+1==level[v])  
        {  
            if(edge[u][v].c>edge[u][v].f)  
            {  
                t=dinic_dfs(v,M,min(tmp,edge[u][v].c-edge[u][v].f));  
                edge[u][v].f+=t;  
                edge[v][u].f-=t;  
                tmp-=t;  
            }  
        }  
    }  
    return cp-tmp;  
}  
int dinic(int s ,int t)//求出最大流  
{  
    int sum,tf;  
    sum=tf=0;  
    while(dinic_bfs(t))  
    {  
        while(tf=dinic_dfs(s,t,INF))  
        {  
            sum+=tf;  
        }  
    }  
    return sum;  
}  

int main()
{
     while(cin>>n>>m)
     {
         clr(edge,0);
       for(int i=1;i<=n;i++)
       {
           int a,b,c;
           cin>>a>>b>>c;
           edge[a][b].c+=c;
           
       }
       printf("%d\n",dinic(1,m));
     }
    return 0;
}