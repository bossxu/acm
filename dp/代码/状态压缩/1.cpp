/**
zoj 3471 状态压缩dp
有n块石头两碰撞，后者消失并释放一定的能量，问怎样安排碰撞能使整个过程完成后释放的能量最多。
解题思路：用一个n位的二进制数表示所有的状态。各位为1则有石头，为0表示没有石头，从dp[(1<<n)-1]倒推，
最后合并成只有一个石头的状态取最大即为答案。
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[(1<<10)+10];
int a[12][12];
int n;

int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
              scanf("%d",&a[i][j]);
        for(int i=(1<<n)-1;i>=0;i--)
            for(int j=0;j<n;j++)
            {
                 if(i&(1<<j))
                 {
                     for(int k=0;k<n;k++)
                     {
                         if(k==j)continue;
                         if(i&(1<<k))continue;
                         dp[i]=max(dp[i],dp[i|(1<<k)]+a[j][k]);
                     }
                 }
            }
        int ans=-1;
        for(int i=0;i<10;i++)
        {
            ans=max(dp[1<<i],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
