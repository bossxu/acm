#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
using namespace std;
int map[1005][1005];
bool flag [1005];
int ji;
int n;
bool dfs(int m)
{
    for(int i=1;i<=n;i++)
    {
        if(map[m][i] && ! flag[i])
        {
            flag[m]=true;
               if(!dfs(i)){
                   flag[m]=false;
                   ji=i;
                   return true;
               }
           flag[m]=false;
        }
    }
    return false;
}
int main()
{
    int dp[1005],t;
    while(scanf("%d%d",&n,&t)==2)
    {
       int a,b;
       int i;
       memset(map,0,sizeof(map));
       for(i=1;i<=n-1;i++)
       {
           scanf("%d%d",&a,&b);
           map[a][b]=1;
           map[b][a]=1;
       } 
       memset(flag,false,sizeof(flag));
       int ans = dfs(t);
       if(ans == 0) printf("First player loses");
       else printf("First player wins flying to airport %d\n",ji);
    }
   return 0;
}