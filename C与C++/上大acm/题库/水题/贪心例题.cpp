#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;


int dp[100][100];
int num[100];

int main()
{
    int len,n;
    while(scanf("%d",&len) && len)///木棍的长度
    {
        scanf("%d",&n); ///切点的个数
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i ++)
            scanf("%d",&num[i]);
        ///两个边界
        num[0] = 0;
        num[n+1] = len;

        int i,j,k,minn,p;
        for(i = 1; i <= n + 1; i ++) ///枚举区间的长度
        {
            for(j = 0; j + i <= n + 1; j ++) ///枚举切割区间的起点
            {
                p = j + i;  ///终点
                minn = INF;
                for(k = j+1; k < p; k ++) ///切割的位置
                {
                    ///dp[j][k]为这一段起点到切割点之前更新的值，dp[k][p]为切割点到终点
                    ///num[p] - num[j]为计算起点到终点的长度
                    int temp = dp[j][k]+dp[k][p] + num[p] - num[j];
                    if(temp < minn)
                        minn = temp;
                }
                if(minn != INF)
                    dp[j][p] = minn;
            }

        }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
    }
    return 0;
}

