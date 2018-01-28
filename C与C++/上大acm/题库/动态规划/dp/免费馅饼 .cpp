#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxn 0x3f3f3f3f
#define inf 100001

int main()
{
   int n,a,b;
   int dp[11][100003];
  // int map[11][100003];
   while(scanf("%d",&n)==1 && n)
   {
     memset(dp,0,sizeof(dp));
     //memset(map,0,sizeof(map));
     int m=0;
     for(int i=1;i<=n;i++)
     {
         scanf("%d%d",&a,&b);
         m=max(b,m);
         dp[a][b]++;
     }
     int k=0;
    for(int j=m-1;j>=0;j--)
   {
       for(int i=0;i<=10;i++)
       {
           if(i==0) 
           dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+dp[i][j];
           else if(i==10)
           dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+dp[i][j];
           else
           dp[i][j]=max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]))+dp[i][j];
          
           //k=max(dp[i][j],k);
           //printf("%d =dp[%d][%d]  \n",dp[i][j],i,j); 
       }
   } 
    printf("%d\n",dp[5][0]);
   }
    return 0;
}