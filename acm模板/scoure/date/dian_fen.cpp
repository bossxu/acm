#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<bitset>
#include<vector>
#include<set>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define F(i,a,b)  for (int i=a;i<b;i++)
#define FF(i,a,b) for (int i=a;i<=b;i++)
#define mes(a,b)  memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 1e5+500;

int n, k, ans, root, num, maxn;
int vis[N], size[N], dis[N], maxv[N];   //size[]表示子树结点数量，maxv[]表示最大子树数量，dis[]表示结点到重心距离
int head[N], e;
struct Edge { int v,next,w; } edge[N];
void Init()
{
    ans=e=0;
    mes(head,-1); mes(vis,0);
}
void Addedge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;
}
void dfssize(int u, int fa)    //计算u树的结点数量
{
    size[u]=1;  maxv[u]=0;
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        int v=edge[i].v;
        if(v!=fa && vis[v]==0) {
            dfssize(v, u);
            size[u]+= size[v];
            if(size[v]>maxv[u]) maxv[u]=size[v];    //求出最大子树数量
        }
    }
}
void dfsroot(int r,int u,int fa)     //计算去掉r树后u树的重心，降低复杂度，这里貌似还用到了树形dp；r为大树的重心
{
    if(size[r]-size[u] >maxv[u]) maxv[u]=size[r]-size[u];   //如果u树结点数小于r树除去u树的数量，则u树就反过来以r树除去u树后的结点作为子树
    if(maxv[u]<maxn) maxn=maxv[u], root=u;      //maxv即为最大子树数量，root为重心
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        int v=edge[i].v;
        if(v!=fa && vis[v]==0) dfsroot(r,v,u);
    }
}
void dfsdis(int u,int d,int fa)     //计算u树中各个结点到重心的距离
{
    dis[num++]= d;
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        int v=edge[i].v;
        if(v!=fa && vis[v]==0) dfsdis(v, d+edge[i].w, u);
    }
}
int calc(int u, int d)      //计算在u树中，点对dis()<=k的数量
{
    int ret=0;
    num=0;      //num表示u树中点的数量
    dfsdis(u,d,0);
    sort(dis, dis+num);
    int i=0, j=num-1;
    while(i<j) {    //经典，相向搜索
        while(dis[i]+dis[j]>k && i<j) j--;
        ret+= j-i;
        i++;
    }
    return ret;
}
int cal(int v,int cost)  // 表示==k的
{
    d[v] = cost; deep[0] = 0;
    getdeep(v,0);
    sort(deep+1,deep+deep[0]+1);
    int r = deep[0],res = 0;
    for(int l = 1;l < r;l++)
        while(deep[l]+deep[r] >= k) {
            if(deep[l] + deep[r] == k) res++;
            r--;
        }
    return res;
}
void dfs(int u)
{
    maxn=n;
    dfssize(u, 0);
    dfsroot(u,u,0);     //找到u树中的重心root
    ans+= calc(root, 0);
    vis[root]=1;
    for(int i=head[root]; i!=-1; i=edge[i].next) {  //从重心出发，去掉重心后，再同样搜子树
        int v=edge[i].v;
        if(vis[v]==0) {
            ans-= calc(v, edge[i].w);   //减去v子树，因为下面dfs(v)还要再加上
            dfs(v);
        }
    }
}
int main()
{
    while(~scanf("%d%d", &n,&k)&& (n&&k))
    {
        Init();
        int u,v,l;
        FF(i,1,n-1) {
            scanf("%d%d%d", &u,&v,&l);
            Addedge(u,v,l);
            Addedge(v,u,l);
        }
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
