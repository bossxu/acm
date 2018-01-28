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
  int n;
  int dp[1005],a[1005];
  while(scanf("%d",&n)==1 && n)
  { 
     for(int i=1;i<=n;i++)
     {
       scanf("%d",&a[i]); 
       dp[i]=a[i];
     }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
         {
             if(a[i]>a[j] && dp[i]<dp[j]+a[i])
               dp[i]=dp[j]+a[i];
         }
    }
    int m=0;
    for(int i=1;i<=n;i++)
   {
      m= max(m,dp[i]);
   }
   printf("%d\n",m);
  } 
    return 0;
}