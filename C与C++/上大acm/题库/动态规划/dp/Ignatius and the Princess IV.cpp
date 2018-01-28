#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 0x3f3f3f3f

int main()
{
    int dp[100000];
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(dp,0,sizeof(dp));
        int item,a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            dp[a]++;
            if(dp[a]>n/2)
            item=a;
        }
        printf("%d\n",item);
    }
   return 0;
}