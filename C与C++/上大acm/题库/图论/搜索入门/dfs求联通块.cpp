#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

char dp[102][102];
int idx[102][102];
int M,N;
void dfs(int r,int c,int id)
{
   if(r<0||r>=M||c<0||c>=N) return ;
   if(idx[r][c]>0 || dp[r][c] != '@') return ;
   idx[r][c]=id;
   for(int dr = -1; dr<=1;dr ++)
   {
       for(int dc= -1;dc<=1;dc ++)
       {
           if(dr!=0 || dc!=0) dfs(r+dr,c+dc,id);
       }
   }
}
int main()
{
   while(scanf("%d%d",&M,&N)==2&& (M || N))
   {
     memset(idx,0,sizeof(idx));
     int i,j;
     for(i=0;i<M;i++)
     {
        scanf("%s",dp[i]);
     }
     
     int cou = 0;
       for(i=0;i<M;i++)
       {
           for(j=0;j<N;j++)
           {
               if(idx[i][j]==0 && dp[i][j]=='@') dfs(i,j,++cou);
           }
       }
       printf("%d\n",cou);
   }
   return 0;
}
