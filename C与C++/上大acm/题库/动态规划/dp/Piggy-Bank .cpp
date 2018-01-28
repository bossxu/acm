#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxn 0x3f3f3f3f
#define inf 1000000

int main()
{
   int t,n;
   cin>>t;
   int dp[10005],zhong[505],jia[505];
   while(t--)
   {
       int st,end;
        memset(dp,maxn,sizeof(dp));
          cin>>st>>end;
          cin>>n;
          for(int i=1;i<=n;i++)
          {
              scanf("%d%d",&jia[i],&zhong[i]);
              dp[zhong[i]]=jia[i];
          }
          dp[0]=0;
          for(int i=1;i<=n;i++)
          {
            for(int j=zhong[i];j<=end-st;j++)
            {
               if(dp[j-zhong[i]]!=maxn)
              dp[j]=min(dp[j-zhong[i]]+jia[i],dp[j]);
            }            
          }
         if(dp[end-st]==maxn) printf("This is impossible.\n");
         else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[end-st]);       
   }
    return 0;
}