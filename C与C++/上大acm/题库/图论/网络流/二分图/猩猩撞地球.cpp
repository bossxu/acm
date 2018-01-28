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
const int maxn=1010;
// 知识点分解：二分图
int V;
vector<int>G[maxn];
int match[maxn];
int vis[maxn];
void add_edge(int from, int to)
{
    G[from].push_back(to);
    G[to].push_back(from);
}
bool dfs(int v)
{
    vis[v]=1;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0 || !vis[w] && dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int max_match()
{
    int res=0;
    clr(match,-1);
    for(int v=1;v<=V;v++)
    {
        if(match[v]<0)
        {
            clr(vis,0);
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        V=2*n;
        for(int i=1;i<=k;i++)
        {
            int a,b;
            cin>>a>>b;
            add_edge(a,b+n);
        }
        printf("%d\n",max_match());
    }
    return 0;
}