#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxn 0x3f3f3f3f

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i,j;
        int dp[2002],a[2002],cun[2002];
        a[0]=0,dp[0]=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
           scanf("%d",&a[i]);
        }
        dp[1]=a[1];
        for(i=2;i<=n;i++)
        {
            scanf("%d",&cun[i]);
        }
        for(i=2;i<=n;i++)
        {
           dp[i]=min(dp[i-1]+a[i],dp[i-2]+cun[i]);
        }
      
        int miao,fen,shi;
        miao = dp[n];
        fen = miao/60;
        shi = fen /60;
        miao %=60;
        fen%=60;
        shi = (shi+8)%24;
        if(shi>=12) 
        printf("%d%d:%d%d:%d%d pm\n",shi/10,shi%10,fen/10,fen%10,miao/10,miao%10);
        else
        printf("%d%d:%d%d:%d%d am\n",shi/10,shi%10,fen/10,fen%10,miao/10,miao%10);
 }
    return 0;
}