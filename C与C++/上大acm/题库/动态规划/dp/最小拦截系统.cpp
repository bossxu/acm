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
    int n;
    int dp[1005],a[1005];
    while(scanf("%d",&n)==1)
    {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=1;
        }
       
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j] && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
    }
    int m=0;
    for(int i=1;i<=n;i++)
    {
        //printf("%d\n",dp[i]);
        if(dp[i]>m)
        m= dp[i];
    }
    printf("%d\n",m);
    }
    return 0;
}