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
int dp[105][105];
int main()
{
    int n,m,s,k;
    int nai[105],ex[105];
    while(scanf("%d%d%d%d",&n,&m,&k,&s)==4)
    {
       for(int i=1;i<=k;i++)
       {
        scanf("%d%d",&ex[i],&nai[i]);
       }
       clr(dp,0);
       for(int i=1;i<=k;i++)
       {
           for(int j=nai[i];j<=m;j++)
           {
               for(int a=1;a<=s;a++)
                 dp[a][j]=max(dp[a][j],dp[a-1][j-nai[i]]+ex[i]);
           }
       }

      if(dp[s][m]<n) printf("-1\n");
      else
      {
          int k=0;
        while(dp[s][m-1]>=n)
        {
            k++;m=m-1;
        }
        printf("%d\n",k);
      }
    }
    return 0;
}