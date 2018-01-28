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
int ch[5]={1,5,10,25,50};
ll dp[102][305];
void init ()
{
    clr(dp,0);
    dp[0][0]=1;
    for(int i=0;i<5;i++)
    {
        for(int j=ch[i];j<=250;j++)
        {
          for(int m=1;m<=100;m++)
          {
              dp[m][j]+=dp[m-1][j-ch[i]];
          }
        }
    }
}
    
int main()
{
    int n;
    init();
    while(scanf("%d",&n)==1 )
     {
       ll ans=0;
       for(int i=0;i<=100;i++)
       {
           ans+=dp[i][n];
       }
        printf("%lld\n",ans);
     }
    return 0;
}