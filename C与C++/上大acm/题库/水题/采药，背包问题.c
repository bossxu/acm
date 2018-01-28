#include<stdio.h>
#include<string.h>
//±³°üÎÊÌâ
int MAX(int a,int  b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int i,j;
    int n,m;
    int v[105],u[105];
    int Dp[1005];
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&v[i],&u[i]);
        }
        memset(Dp,0,sizeof(Dp));
        for(i=1;i<=m;i++)
        {
            for(j=n;j>=v[i];j--)
            {
                Dp[j]=MAX(Dp[j],Dp[j-v[i]]+u[i]);
            }
        }
        printf("%d\n",Dp[n]);
    }
    return 0;
}
