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
// 知识点分解：二分图 最大匹配
const int maxn = 500;
int G[maxn][100]; // 前课后时
int n;
int match[maxn];
int vis[maxn];

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
    while(cin>>n)
    {
        clr(G,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            while(a--)
            {
                int b,c;
                cin>>b>>c;
                G[i][b*12+c-12]=1;
            }
        }
        printf("%d\n",max_match());
    }  
    return 0;
}