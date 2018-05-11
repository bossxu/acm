#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int> G[maxn];
int vis[maxn];
int N,M;
int ans;
bool flag;
int head;
void dfs(int u,int fa)
{
    vis[u]=1;
    if(G[u].size()!=2)
        flag=true;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)
            continue;
        if(!vis[v])
            dfs(v,u);
        if(v==head&&!flag)
        {
            ans++;
            return ;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N>>M)
    {
        for(int i=0;i<maxn;i++)
            G[i].clear();
        memset(vis,0,sizeof(vis));
        int u,v;
        ans=0;
        while(M--)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=N;i++)
        {
            if(!vis[i])
            {
                head=i;
                flag=false;
                dfs(i,-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
