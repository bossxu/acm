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
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
int main()
{
    int map[105][105];
    int dp[105];
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n+m==0) break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>map[i][j];
            }
        }
        clr(dp,0);
       for(int i=1;i<=n;i++)
         {
             for(int j=m;j>0;j--)
             {
                 for(int k=1;k<=m;k++)
                 {
                     if(j-k>=0)
                         dp[j]=max(dp[j],dp[j-k]+map[i][k]);
                 }
             }
         }
        printf("%d\n",dp[m]);
    }
    return 0;
}