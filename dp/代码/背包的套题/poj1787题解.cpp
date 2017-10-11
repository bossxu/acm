#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define  MAX_M 10005
#define MAX_N 10
//dp[i][j]的定义就是使用前i中硬币时，支付j元第i种硬币最多可以剩余多少个
int dp[MAX_M];
int path[MAX_M];//path[j]元的定义是生成j元的前一步是多少元，j-path【j】就可以算出加上的这个硬币面额的差值
int used[MAX_M];//代表使用该种硬币的个数
int ans[MAX_M];
int v[5] ={1,5,10,25};  
int m[MAX_N];//代表起初各种硬币的数目
int s[MAX_N];//代表完成支付后各种硬币的数目
int M;//代表总钱数
int main()
{
    //freopen("背包H-多重背包方案记录.txt", "r",stdin);  
    while(~scanf("%d",&M))
    {
        memset(dp,0,sizeof(dp));

        memset(ans,0,sizeof(ans));

        memset(path,0,sizeof(path));

        for(int i=0;i<4;i++)
        {
            scanf("%d",m+i);

        }

        if(M==m[0]&&m[0]==m[1]&&m[1]==m[2]&&m[2]==m[3]&&m[3]==0)
        {
            break;
        }
        void solve();
        solve();
    }
    return 0;

}
void solve()
{

    dp[0]=1;
    //因为尽可能的支付的硬币数要多，所以又贪心的思想我们可知，要尽可能选取面额小的硬币种类

    for(int i=0;i<4;i++)
    {
        memset(used,0,sizeof(used));
        for(int j=v[i];j<=M;j++)
        {
            if(dp[j-v[i]]&&dp[j-v[i]]+1>dp[j]&&used[j-v[i]]<m[i])
            {
                dp[j]=dp[j-v[i]]+1;
                used[j]=used[j-v[i]]+1;
                path[j]=j-v[i];//j元的前一步是j-v[i],记录路径
                //cout<<"path "<<path[j]<<" i   "<<i<<"  j "<<j<<" j-v[i] "<<j-v[i]<<endl;
            }
        }
    }

    int i=M;
    if(dp[M]>0)
    {
        while(i!=0)
        {
            ans[i-path[i]]++;
            i=path[i];
        }
        printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[1],ans[5],ans[10],ans[25]);
    }
    else{
        printf("Charlie cannot buy coffee.\n");
    }

}
