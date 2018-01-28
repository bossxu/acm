#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;


int dp[100][100];
int num[100];

int main()
{
    int len,n;
    while(scanf("%d",&len) && len)///ľ���ĳ���
    {
        scanf("%d",&n); ///�е�ĸ���
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i ++)
            scanf("%d",&num[i]);
        ///�����߽�
        num[0] = 0;
        num[n+1] = len;

        int i,j,k,minn,p;
        for(i = 1; i <= n + 1; i ++) ///ö������ĳ���
        {
            for(j = 0; j + i <= n + 1; j ++) ///ö���и���������
            {
                p = j + i;  ///�յ�
                minn = INF;
                for(k = j+1; k < p; k ++) ///�и��λ��
                {
                    ///dp[j][k]Ϊ��һ����㵽�и��֮ǰ���µ�ֵ��dp[k][p]Ϊ�и�㵽�յ�
                    ///num[p] - num[j]Ϊ������㵽�յ�ĳ���
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

