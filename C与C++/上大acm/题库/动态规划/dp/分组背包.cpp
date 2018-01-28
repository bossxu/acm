#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;  //hdu 3033
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
int dp[12][10005];
int main()
{
    int n,m,t;
    int zu[105],mon[105],happy[105];
    while(scanf("%d%d%d",&n,&m,&t)==3)
    { 
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&zu[i],&mon[i],&happy[i]);
        }
        for(int i=0;i<=t;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                dp[i][j]=0;
                else
                dp[i][j]=-INF;
            }
        }
        for(int i=1;i<=t;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(zu[j]==i)
               {
                   for(int k=m;k>=mon[j];k--)
                   {
                       dp[i][k]=max(dp[i][k],max(dp[i][k-mon[j]]+happy[j],dp[i-1][k-mon[j]]+happy[j]));
                   }
               }
            }
        }
        if(dp[t][m]<0)
        printf("Impossible\n");
        else
        printf("%d\n",dp[t][m]);
    }
    return 0;
}