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
// 知识点分解：二分图 匈牙利算法
int V;
const int maxn= 305;
int G[maxn][maxn];
int match[maxn];
int vis[maxn];
int p,n;
bool dfs(int v)
{
    for(int i=1;i<=n;i++)
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
    for(int v=1;v<=p;v++)
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
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&p,&n);
        clr(G,0);
        int ite=0;
        if(p>n) ite=1;
        for(int i=1;i<=p;i++)
        {
            int c;
            scanf("%d",&c);
            while(c--)
            {
                int a;
                scanf("%d",&a);
                if(a==0) ite=1;
                G[i][a]=1;
            }            
        }
        if( !ite && max_match()==p)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

    }
    //system("pause");
    return 0;
}