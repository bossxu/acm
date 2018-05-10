#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
const int maxn=200005;
vector<int>G[maxn];
bool vis[maxn];
int n,m;
int item,tou,flag;
void dfs(int u,int fa)
{
    vis[u]=1;
    if(G[u].size()!=2)
        flag=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)
            continue;
        if(!vis[v])
            dfs(v,u);
        if(v==tou && flag)
        {
            item++;
            return ;
        }
    }
}
int main()
{
  while(cin>>n>>m)
  {
    item = 0;
    int a,b;
    clr(vis,0);
    for(int i = 1;i<=m;i++)
    {
      scanf("%d%d",&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
        if(vis[i]) continue;
        flag = 1;
        tou = i;
        dfs(i,-1);
    }
    cout<<item<<endl;
  }
  return 0;
}
