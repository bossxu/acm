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
int t;
// 知识点分解：
bool dfs(int v)
{
    for(int i=1;i<=84;i++)
    {   
        if(G[v][i]&&!vis[i])
        {
            vis[i]=1;
            if(match[i]<0 || dfs(match[i]))
            {
                match[i]=v;
                return true;
            }
        }
    }
    return false;
}
int max_match()
{
    int res=0;
    clr(match,-1);
    for(int v=1;v<=n;v++)
    {
            clr(vis,0);
            if(dfs(v))
            {
                res++;
            }
    }
    return res;
}
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        clr(g,1);
        while(k--)
        {
          int a,b;
          cin>>a>>b;
          G[a][b]=0;
        }
         t = n*m-k;
        if(t%2!=0)
        {
            printf("NO\n");
        }
        else
        {
            t/=2;
        }
    }
    return 0;
}