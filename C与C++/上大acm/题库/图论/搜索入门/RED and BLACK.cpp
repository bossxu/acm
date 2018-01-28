#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,cnt;
char dp[22][22];
int vis[22][22];
int check(int x ,int y)
{
  if(x<0 || y<0 ||x>=n ||y>=m || dp[x][y]!='.')
  {
      return 0;
  } 
  if(vis[x][y] == 1 ) return 0;
  
  return 1;
}
void dfs(int a,int b)
{
   
    cnt++;
    vis[a][b]=1;
    for(int da=-1;da<=1;da++)
    {
        for(int db=-1;db<=1;db++)
        {
            if(da!=db && da+db!=0 && check(a+da,b+db))
            {
                dfs(a+da,b+db);
            }
        }
    } 
}
int main()
{
  while(scanf("%d%d",&m,&n)==2 && n && m)
  {
    int i,j;
    cnt=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",dp[i]);
    }
    int a,b;
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++) 
       for(j=0;j<m;j++)
          if(dp[i][j]=='@') 
             {
                 a=i;b=j;
             }
             
    dfs(a,b);
    printf("%d\n",cnt);
  }
    return 0;
}